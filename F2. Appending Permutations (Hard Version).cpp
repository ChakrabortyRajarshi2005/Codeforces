F2. Appending Permutations (Hard Version)
time limit per test3 seconds
memory limit per test1024 megabytes

This is the hard version of the problem. The difference between the versions is that in this version, n≤5000
. You can hack only if you solved all versions of this problem.

You are given an initially empty array a
. You may perform the following operation any number of times:

Choose an integer s≥1
 and append a cyclic shift of the array [1,2,…,s]
 to the end of a
. Formally, select integers s
 and r
 such that 1≤r≤s
, and append the array
[r,r+1,…,s,1,2,…,r−1]

to the end of a
.

You are also given an integer n
 and m
 restrictions of the form ai≠x
. That is, for each of the m
 restrictions, the value at position i
 in the final array must not be equal to x
.
Your task is to count the number of distinct arrays of length exactly n
 that can be constructed using the allowed operation and satisfy all of the given restrictions. Two arrays are considered different if they differ at any position from 1
 to n
.

Print the answer modulo 998244353
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤5000
). The description of the test cases follows.

The first line of each test case contains two integers n
 and m
 (1≤n≤5000,0≤m≤min(5000,n2)
) — the length of the array a
 and the number of restrictions.

The following m
 lines each contain two integers i
 and x
 (1≤i,x≤n
), indicating that ai≠x
 is a requirement of the final array. It is guaranteed that no limitation is given more than once.

It is guaranteed that the sum of n
 over all test cases does not exceed 5000
, and the sum of m
 over all test cases does not exceed 5000
.

Output
For each test case, output the number of arrays modulo 998244353
.

Examples
InputCopy
7
3 0
3 3
1 1
2 1
3 1
3 2
1 1
2 1
6 2
2 3
4 2
2 3
1 2
2 2
1 1
4 3
2 2
3 2
4 2
3 2
2 3
3 3
OutputCopy
7
0
1
65
0
4
5
InputCopy
1
5000 1
69 420
OutputCopy
886908216
Note
In the first test case, there are 7
 total attainable arrays: [1,2,3],[2,3,1],[3,1,2],[1,1,2],[1,2,1],[2,1,1],[1,1,1]
.

In the second test case, none of the above 7
 are valid because no element is allowed to be 1
, and all of the arrays have at least one 1
.

In the third case, only [2,3,1]
 is counted.
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
template<typename T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[ ";
    for(const auto& elem : vec) {
        os << elem << " ";
    }
    os << "]";
    return os;
}
struct Mint {
    int v;
    Mint(long long val = 0) {
        v = int(val % MOD);
        if (v < 0) v += MOD;
    }
    Mint operator+(const Mint &o) const { return Mint(v + o.v); }
    Mint operator-(const Mint &o) const { return Mint(v - o.v); }
    Mint operator*(const Mint &o) const { return Mint(1LL * v * o.v); }
    Mint operator/(const Mint &o) const { return *this * o.inv(); }
    Mint& operator+=(const Mint &o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    Mint& operator-=(const Mint &o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    Mint& operator*=(const Mint &o) { v = int(1LL * v * o.v % MOD); return *this; }
    Mint pow(long long p) const {
        Mint a = *this, res = 1;
        while (p > 0) {
            if (p & 1) res *= a;
            a *= a;
            p >>= 1;
        }
        return res;
    }
    Mint inv() const { return pow(MOD - 2); }
    friend ostream& operator<<(ostream& os, const Mint& m) {
        os << m.v;
        return os;
    }
};
void solve() {
    int N, K;
    cin >> N >> K;

    vector<vector<bool>> banned(N, vector<bool>(N));
    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;
        banned[x - 1][y - 1] = true;
    }

    vector<Mint> tot(N + 1);
    tot[N] = 1;
    vector<vector<Mint>> dp(N + 1, vector<Mint>(N + 1));
    vector<vector<int>> chain(N + 1, vector<int>(N + 1));

    for (int i = N - 1; i >= 0; --i) {
        for (int j = N - 1; j >= 0; --j) {
            chain[i][j] = 1 + chain[i + 1][j + 1];
            if (banned[i][j]) chain[i][j] = 0;
        }
    }

    vector<vector<Mint>> ssum(N + 2, vector<Mint>(N + 1));

    for (int i = N - 1; i >= 0; --i) {
        for (int j = 0; j <= N - i; ++j) {
            if (j == 0) {
                for (int len = 1; len <= N - i; ++len) {
                    bool ok = chain[i][0] >= len;
                    if (!ok) break;
                    dp[i][j] += tot[i + len];
                    dp[i][j] -= dp[i + len][j + len];
                }
            } else {
                if (chain[i][j]) {
                    dp[i][j] += ssum[i + 1][j];
                    if (i + 1 + chain[i][j] <= N) {
                        dp[i][j] -= ssum[i + 1 + chain[i][j]][j];
                    }
                }
            }
            tot[i] += dp[i][j];
        }

        for (int j = 1; j < N; ++j) {
            ssum[i][j] = ssum[i + 1][j];
            if (chain[i][0] >= j) {
                ssum[i][j] += tot[i + j];
            }
        }
    }
    // cout << dp << endl;
    // cout << ssum << endl;
    cout << tot[0].v << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}
