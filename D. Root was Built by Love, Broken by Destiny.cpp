D. Root was Built by Love, Broken by Destiny
time limit per test2 seconds
memory limit per test256 megabytes
Heartfall River runs horizontally through Destinyland and divides it into the northern and southern sides.

Engineer Root wants to build n
 houses along the river, numbered from 1
 to n
. All houses on the northern side and all houses on the southern side must lie along straight lines parallel to Heartfall River.

There will be m
 bridges, with the i
-th bridge connecting house ui
 and house vi
 (ui≠vi
). It is guaranteed that all n
 houses are connected by these bridges, that is, you can travel from any house to any other by crossing bridges. Also, there are no two bridges connecting the same pair of houses.

Root wants to know how many ways there are to arrange the n
 houses along the river, modulo 109+7
, such that the following conditions hold for the planned m
 bridges:

For every bridge, the two houses it connects lie on opposite sides of the river;
The bridges do not cross when drawn as straight lines between the houses.
A possible arrangement of the houses when n=5
.
Two arrangements are considered different if at least one of the following conditions holds:

There exists a house that lies on a different side in each arrangement;
There exist two houses a
 and b
 that are on the same side in both arrangements, but a
 comes before b
 in one arrangement and b
 comes before a
 in the other.
Since Root is distracted by his ex, whom destiny separated from him, he asks you to calculate the number of ways to arrange the houses along the river, modulo 109+7
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains two integers n
 and m
 (2≤n≤2⋅105
, n−1≤m≤min(n(n−1)2,2⋅105)
) — the number of houses and the number of bridges.

Then m
 lines follow, the i
-th line containing two integers ui
 and vi
 (1≤ui,vi≤n
, ui≠vi
) — the two houses that the i
-th bridge connects.

It is guaranteed that all the n
 houses are connected by the bridges, and there are no two bridges connecting the same pair of houses.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
, and the sum of m
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the number of ways to arrange the n
 houses along the river, modulo 109+7
.

Example
InputCopy
4
2 1
1 2
3 3
1 2
1 3
2 3
5 4
1 2
1 3
3 4
3 5
4 3
1 2
1 3
1 4
OutputCopy
2
0
8
12
Note
In the first test case, either house 1
 should be built on the northern side and house 2
 on the southern side, or vice versa.

In the second test case, at least two houses must be built on the same side of the river. But every pair of houses is connected by a bridge. So in every arrangement, at least one bridge will not cross the river. Thus, the answer is 0
.

In the third test case, one of the possible arrangements of the houses is provided in the problem statement.
#include <bits/stdc++.h>
using namespace std;

#define SZ(x) int(x.size())

const int  MOD    = 1e9  + 7;
const int MXN    = 2e5  + 5;

int n, m, fact[MXN];
vector<int> adj[MXN];

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    fact[0] = 1;
    for (int i = 1; i < MXN; i++) 
        fact[i] = (1ll * fact[i-1] * i) % MOD;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long ans = 2;
        int tl = 0;
        if (m >= n) ans = 0;
        for (int u = 1; u <= n; u++) {
            if (adj[u].size() > 1) {
                int x = 0;
                for (int v : adj[u]) {
                    x += (SZ(adj[v]) == 1);
                }
                if (x >= SZ(adj[u]) - 2) (ans *= fact[x]) %= MOD;
                else ans = 0;
            } else tl ++;
        }
        if (tl < n-1) tl = 2; else tl = 1;
        cout << (ans * tl % MOD) << '\n';
    }
    return 0;
}
