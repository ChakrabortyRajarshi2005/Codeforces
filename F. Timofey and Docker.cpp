F. Timofey and Docker
time limit per test2 seconds
memory limit per test512 megabytes
Not so long ago, a certain Timofey learned about docker and now wants to present a report about it at a conference. He has already prepared the text s
.

There are n
 people attending the conference. The i
-th attendee will understand Timofey's report if the number of occurrences of the word "docker" as a contiguous substring in the text is not less than li
 and not greater than ri
.

To ensure that as many people as possible learn about docker, Timofey can change characters in his text.

Help Timofey determine the minimum number of characters that need to be changed so that the topic is understood by the maximum possible number of attendees.

Input
Each test consists of several test cases. The first line contains an integer t
 (1≤t≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains one string s
 (1≤|s|≤5⋅105
) — Timofey's text, which consists of lowercase Latin letters.

The second line of each test case contains one integer n
 (1≤n≤5⋅105
) — the number of attendees.

The next n
 lines of each test case contain two integers li,ri
 (1≤li≤ri≤109
).

Additional constraints on the input data:

The sum of |s|
 across all test cases does not exceed 5⋅105
;
The sum of n
 across all test cases does not exceed 5⋅105
.
Output
For each test case, print one integer — the minimum number of characters that need to be changed so that the topic is understood by the maximum number of attendees.

Examples
InputCopy
2
dockerdockerxxxxxx
3
3 3
2 4
1 5
ljglsjfkdieufj
5
1 5
3 3
2 4
3 7
2 9
OutputCopy
6
11
InputCopy
4
dockerdockerdockerdockzzdockzz
4
1 1
1 1
4 5
4 5
docker
5
1 1
2 2
3 3
4 4
5 5
ddddddoooooocccccckkkkkkeeeeeerrrrrr
10
1 200
500 600
1 600
6 6
6 6
500 2000
6 400
89 90
4 7
1 10
dockerdockerdockerdockzzdockzz
4
2 2
2 2
4 5
4 5
OutputCopy
2
0
30
1
Note
Let's consider the first test in more detail:

in the first test case, it is possible to change all the characters 'x
' at the end of the string to the whole word "docker
", so that all 3
 people will understand the topic;
in the second test case, it is possible to change some characters in s
 as follows: "ldockerkdocker
" and the topic will be understood by 3
 people, which is the maximum.


#include <bits/stdc++.h>
using namespace std;
 
#define forn(i, n) for(int i = 0; i < int(n); i++) 
 
const int INF = 1e8;
const string al = "docker";
 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--){
        string s;
        cin >> s;
        int n = s.size();
        int mx = n / 6;
        int m;
        cin >> m;
        vector<int> dx(mx + 2);
        forn(i, m){
            int l, r;
            cin >> l >> r;
            r = min(r, mx);
            if (l > r) continue;
            ++dx[l];
            --dx[r + 1];
        }
        forn(i, mx + 1) dx[i + 1] += dx[i];
 
        int cur = 0;
        vector<int> dif(max(0, n - 5));
        forn(i, n - 5){
            forn(j, 6)
                dif[i] += s[i + j] != al[j];
            cur += dif[i] == 0;
        }
 
        int mxcnt = *max_element(dx.begin(), dx.end());
        int k = -1;
        int ans = INF;
        forn(i, mx + 1){
            if (dx[i] != mxcnt) continue;
            if (i <= cur){
                ans = min(ans, cur - i);
                continue;
            }
            k = i;
            break;
        }
 
        if (k == -1){
            cout << ans << '\n';
            continue;
        }
 
        auto calc = [&](int d){
            vector<pair<long long, int>> dp(n + 1, {(long long)1e18, -1});
            dp[0] = {0, 0};
            forn(i, n){
                dp[i + 1] = min(dp[i + 1], dp[i]);
                if (i + 6 <= n)
                    dp[i + 6] = min(dp[i + 6], {dp[i].first + dif[i] + d, dp[i].second - 1});
            }
            return dp[n];
        };
 
        int l = -INF, r = 0, sv = INF;
        while (l <= r){
            int m = (l + r) / 2;
            auto [val, cnt] = calc(m);
            if (-cnt >= k){
                sv = val - k * 1ll * m;
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        ans = min(ans, sv);
 
        cout << ans << '\n';
    } 
}
