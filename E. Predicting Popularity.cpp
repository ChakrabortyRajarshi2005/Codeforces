E. Predicting Popularity
time limit per test3 seconds
memory limit per test256 megabytes
Imagine that you are working at Berflix — the largest streaming service in Berland, specialized in movie distribution. The audience of this service consists of n
 users, and for each of them, some preferences are known: the level of action in a movie ai
 and the level of drama di
.

Your current task is to try to predict the popularity of a certain movie. Let the movie you are interested in contain ac
 "units" of action and dr
 "units" of drama (data kindly provided by the analytics team). If both the action and drama levels in the movie meet or exceed the threshold values for a certain user, they will definitely watch the movie.

If the movie falls short in either action or drama, the user will hesitate. However, the popularity of the movie among other viewers may sway them to watch it. After lengthy discussions, your team has chosen the following model of events.

Let p
 be the number of people who have already watched the movie (initially p=0
). We will consider that the movie is suitable for user i
 if max(ai−ac,0)+max(di−dr,0)≤p
.

Users constantly check recommendations. Therefore, we will assume that as long as there exists a user who has not yet watched the movie but finds it suitable, they will definitely watch it. Watching the movie will increase its popularity p
 by one and may make it suitable for other users.

This process will conclude when either everyone has watched the movie, or none of the remaining viewers find it suitable. Your task is to count how many people will watch the movie in total.

There is one last problem — the users' preferences are constantly changing. Specifically, there are m
 requests to change the values of ak
 and dk
 for some user k
, and you need to recalculate the final popularity of the movie p
 after each change.

Input
The first line contains two numbers ac
 and dr
 (1≤ac,dr≤106
) — the action and drama ratings of the movie.

The second line contains one integer n
 (1≤n≤5⋅105
) — the number of users of Berflix.

The third line contains n
 numbers a1,a2,…,an
 (1≤ai≤106
) — the users' preferences for action.

The fourth line contains n
 numbers d1,d2,…,dn
 (1≤di≤106
) — the users' preferences for drama.

The fifth line contains one integer m
 (1≤m≤3⋅105
) — the number of changes in user preferences.

The following m
 lines contain the changes in the format:

"kj
 naj
 ndj
" (1≤kj≤n
; 1≤naj,ndj≤106
), where naj
 is the new preference of user kj
 for action, and ndj
 — for drama.
Output
For each change request, output the total number of views of the movie p
 after updating the information about the corresponding user.

Example
InputCopy
20 25
4
1 22 1 30
1 22 50 30
5
3 1 25
2 23 22
4 10 27
1 21 21
3 20 26
OutputCopy
3
2
4
4
0
Note
Consider the first request. The first and third viewers already find the movie suitable, so they will watch it, increasing the popularity p
 by 2
. With p=2
, the movie will become suitable for the second viewer. As a result, they will also watch it, increasing the popularity by another 1
. However, the 4
-th viewer still does not find the movie suitable, as max(30−20,0)+max(30−25,0)>3
.

Thus, after the first request, 3
 people will watch the movie.


#include<bits/stdc++.h>
 
using namespace std;
 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())
 
#define x first
#define y second
 
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
 
template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
    fore(i, 0, sz(v)) {
        if(i) out << " ";
        out << v[i];
    }
    return out;
}
 
const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
 
int ac, dr;
int n;
vector<int> a, d;
 
inline bool read() {
    if(!(cin >> ac >> dr))
        return false;
    cin >> n;
    a.resize(n);
    fore (i, 0, n)
        cin >> a[i];
    d.resize(n);
    fore (i, 0, n)
        cin >> d[i];
    return true;
}
 
vector<int> Tadd, Tmin;
 
void push(int v) {
    Tadd[2 * v + 1] += Tadd[v];
    Tadd[2 * v + 2] += Tadd[v];
    Tadd[v] = 0;
}
 
int getmin(int v) {
    return Tmin[v] + Tadd[v];
}
 
void upd(int v) {
    Tmin[v] = min(getmin(2 * v + 1), getmin(2 * v + 2));
}
 
void init(int v, int l, int r) {
    if (l + 1 == r) {
        Tmin[v] = -l;
        return;
    }
    int mid = (l + r) >> 1;
    init(2 * v + 1, l, mid);
    init(2 * v + 2, mid, r);
    upd(v);
}
 
void init(int n) {
    Tadd.assign(4 * n, 0);
    Tmin.resize(4 * n);
    init(0, 0, n);
}
 
void addVal(int v, int l, int r, int lf, int rg, int val) {
    if (l == lf && r == rg) {
        Tadd[v] += val;
        return;
    }
    int mid = (l + r) >> 1;
    push(v);
    if (lf < mid)
        addVal(2 * v + 1, l, mid, lf, min(mid, rg), val);
    if (rg > mid)
        addVal(2 * v + 2, mid, r, max(lf, mid), rg, val);
    upd(v);
}
 
int firstNeg(int v, int l, int r) {
    if (l + 1 == r) {
        assert(getmin(v) < 0);
        return l;
    }
    push(v);
    int mid = (l + r) >> 1;
    int ans = -1;
    if (getmin(2 * v + 1) < 0)
        ans = firstNeg(2 * v + 1, l, mid);
    else
        ans = firstNeg(2 * v + 2, mid, r);
    upd(v);
    return ans;
}
 
int calcDemand(int i) {
    return min(n, max(a[i] - ac, 0) + max(d[i] - dr, 0));
}
 
inline void solve() {
    init(n + 2);
    fore (i, 0, n) {
        int p = calcDemand(i);
        addVal(0, 0, n + 2, p + 1, n + 2, 1);
    }
 
    int m; cin >> m;
    fore (j, 0, m) {
        int k, na, nd;
        cin >> k >> na >> nd;
        k--;
        int p = calcDemand(k);
        addVal(0, 0, n + 2, p + 1, n + 2, -1);
        a[k] = na;
        d[k] = nd;
        p = calcDemand(k);
        addVal(0, 0, n + 2, p + 1, n + 2, 1);
 
        int ans = firstNeg(0, 0, n + 2);
        cout << ans - 1 << '\n';
    }
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    
    if(read()) {
        solve();
        
#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
#endif
    }
    return 0;
}
