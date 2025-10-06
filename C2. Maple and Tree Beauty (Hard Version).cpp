C2. Maple and Tree Beauty (Hard Version)
time limit per test6 seconds
memory limit per test1024 megabytes

This is the hard version of the problem. The difference between the versions is that in this version, the constraints on t
 and n
 are larger. You can hack only if you solved all versions of this problem.

Maple is given a rooted tree consisting of n
 vertices numbered from 1
 to n
, where the root has index 1
. Each vertex of the tree is labeled either zero or one. Unfortunately, Maple forgot how the vertices are labeled and only remembers that there are exactly k
 zeros and n−k
 ones.

For each vertex, we define the name of the vertex as the binary string formed by concatenating the labels of the vertices from the root to the vertex. More formally, name1=label1
 and nameu=namepu+labelu
 for all 2≤u≤n
, where pu
 is the parent of vertex u
 and +
 represents string concatenation.

The beauty of the tree is equal to the length of the longest common subsequence∗
 of the names of all the leaves†
. Your task is to determine the maximum beauty among all labelings of the tree with exactly k
 zeros and n−k
 ones.

∗
A sequence a
 is a subsequence of a sequence b
 if a
 can be obtained from b
 by the deletion of several (possibly, zero or all) element from arbitrary positions. The longest common subsequence of strings s1,s2,…sm
 is the longest string that is a subsequence of all of s1,s2,…,sm
.

†
A leaf is any vertex without children.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains two integers n
 and k
 (2≤n≤2⋅105
, 0≤k≤n
) — the number of vertices and the number of vertices labelled with zero, respectively.

The second line contains n−1
 integers p2,p3,…,pn
 (1≤pi≤i−1
) — the parent of vertex i
.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer representing the maximum beauty among all labelings of the tree with exactly k
 zeroes and n−k
 ones.

Examples
InputCopy
5
7 3
1 1 2 2 3 3
7 2
1 1 2 3 1 1
5 0
1 2 3 4
5 2
1 1 1 1
5 4
1 1 1 1
OutputCopy
3
2
5
1
2
InputCopy
5
2 0
1
2 1
1
3 0
1 1
3 1
1 2
3 1
1 1
OutputCopy
2
2
2
3
2
Note

In the first test case, the maximum beauty is 3
, when the vertices are labeled with [0,0,0,1,1,1,1]
, and the longest common subsequence is 001.

In the second test case, the maximum beauty is 2
, when the vertices are labeled with [1,0,0,1,1,1,1]
, and the longest common subsequence is 11.


#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
template <int maxn>
int solve(int n, int k) {
    if (maxn <= n) {
        return solve<min(N, maxn * 2)>(n, k);
    }
    bitset<maxn> dp;
    vector<int> fa(n, -1), dep(n, 0);
    vector<int> noson(n, 1), cnt(n + 1);
    cnt[0]++;
    for (int i = 1; i < n; i++) {
        cin >> fa[i], fa[i]--;
        dep[i] = dep[fa[i]] + 1;
        cnt[dep[i]]++;
        noson[fa[i]] = 0;
    }
    dp.reset();
    dp[0] = 1;
    int mxdep = 1e9;
    for (int i = 0; i < n; i++)
        if (noson[i]) mxdep = min(mxdep, dep[i]);
 
    int sum = 0;
    vector<int> all(cnt.begin(), cnt.begin() + mxdep + 1);
    sort(all.begin(), all.end());
    vector<int> v;
    for (int i = 0; i < (int)all.size(); i++) {
        int j = i;
        while (j + 1 < (int)all.size() && all[i] == all[j + 1]) j++;
        int t = j - i + 1;
        for (int z = 1; z <= t; z *= 2) {
            v.push_back(z * all[i]);
            t -= z;
        }
        if (t > 0) v.push_back(t * all[i]);
        i = j;
    }
    dp[0] = 1;
    for (auto val : v) {
        sum += val;
        dp |= (dp << val);
    }
    if (sum <= k || sum <= n - k) return mxdep + 1;
    for (int i = 0; i <= sum; i++)
        if (dp[i]) {
            if (i <= k && sum - i <= n - k) return mxdep + 1;
        }
    return mxdep;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        cout << solve<1>(n, k) << "\n";
    }
    return 0;
}
