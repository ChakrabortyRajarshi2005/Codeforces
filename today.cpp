#include<bits/stdc++.h>

#define pb push_back 
using namespace std;

const int mxN = 2e5 + 2;

vector<int> divs[mxN];

void pre(){
    for(int i = 2; i<mxN; i++){
        for(int j = i; j<mxN; j+=i)divs[j].pb(i);
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1), cnt(n+1, 0), max_nums;
    vector<bool> vis(n+1, 0);
    for(int i = 1; i<=n; i++)cin>>a[i];

    int ans = 0;
    for(int i = 1; i<=n; i++){
        int x = a[i];
        vector<int> next;
        for(auto &num : divs[x]){
            cnt[num]++;
            if(cnt[num] != i)ans = max(ans, cnt[num]);
            else if(!vis[num]){
                next.pb(num);
                vis[num] = 1;
            }
        }

        for(auto &num : max_nums){
            if(cnt[num] != i){
                ans = max(ans, cnt[num]);
                vis[num] = 0;
            } else next.pb(num);
        }
        max_nums = next;
        cout<<ans<<" \n"[i == n];
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    pre();
    while(t--)solve();
    return 0;
}
