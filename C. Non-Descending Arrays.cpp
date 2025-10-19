C. Non-Descending Arrays
time limit per test2 seconds
memory limit per test256 megabytes
You are given two integer arrays a
 and b
 both of length n
.

You can choose any subset of indices and swap the elements at those positions (i. e. make a swap(ai
, bi
) for each i
 in the subset). A subset of indices is considered good if, after the swapping, both arrays are sorted in non-descending order.

Your task is to calculate the number of good subsets. Since the answer can be large, print it modulo 998244353
.

Input
The first line contains a single integer t
 (1≤t≤500
) — the number of test cases.

The first line of each test case contains a single integer n
 (1≤n≤100
).

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤1000
).

The third line contains n
 integers b1,b2,…,bn
 (1≤bi≤1000
).

Additional constraint on the input: there is at least one good subset.

Output
For each test case, print a single integer — the number of good subsets, taken modulo 998244353
.

Example
InputCopy
3
3
2 1 4
1 3 2
1
4
4
5
2 3 3 4 4
1 1 3 5 6
OutputCopy
2
2
8
Note
In the first example, there are 2
 good subsets: {1, 3} and {2}.

In the second example, there are 2
 good subsets: {1} and {}.

In the third example, there are 8
 good subsets: {1, 2, 3, 4, 5}, {1, 2, 3}, {1, 2, 4, 5}, {1, 2}, {3, 4, 5}, {3}, {4, 5} and {}.


#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    int ans = 1;
    for (int i = 0; i < n; ++i) {
      if (a[i] > b[i]) swap(a[i], b[i]);
      if (!i || a[i] >= b[i - 1]) ans = (ans * 2LL) % MOD;
    }
    cout << ans << '\n';
  }
}
