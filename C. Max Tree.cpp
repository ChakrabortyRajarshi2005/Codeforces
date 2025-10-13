C. Max Tree
time limit per test2 seconds
memory limit per test256 megabytes

You are given a tree consisting of n
 vertices, numbered from 1
 to n
. Each of the n−1
 edges is associated with two non-negative integers x
 and y
.

Consider a permutation∗
 p
 of the integers 1
 through n
, where pi
 represents the value assigned to vertex i
.

For an edge (u,v)
, such that u<v
 with associated values x
 and y
, its contribution is defined as follows:
{xyif pu>pv,otherwise.

The value of the permutation is the sum of the contributions from all edges.

Your task is to find any permutation p
 that maximizes this total value.

∗
A permutation of length n
 is an array consisting of n
 distinct integers from 1
 to n
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (n=3
 but there is 4
 in the array).

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line contains a single integer n
 (2≤n≤2⋅105
) — the number of vertices in the tree.

Each of the next n−1
 lines contains four integers u
, v
, x
, and y
 (1≤u<v≤n
, 1≤x,y≤109
) — describing an edge between vertices u
 and v
 with associated values x
 and y
. It is guarranteed that the given edges form a tree.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, you must output a permutation p
 of the integers 1
 through n
 that maximizes the total value as defined in the problem. If there are multiple answers, you can print any of them.

Example
InputCopy
3
3
1 2 2 1
2 3 3 2
5
1 2 1 3
1 5 2 1
2 4 5 7
2 3 1 100
5
2 5 5 2
3 5 4 6
4 5 1 5
1 5 3 5
OutputCopy
3 2 1 
2 3 5 4 1 
1 5 2 3 4 
Note
In the first test case:

Consider the permutation p=[3,2,1]
. Its value is 5=2+3
. Here's why:

Since p1>p2
, the first edge contributes +2
.
Since p2>p3
, the second edge contributes +3
.
The values of some other permutations are as follows:

p=[1,2,3]
 has value 1+2=3
.
p=[1,3,2]
 has value 1+3=4
.
p=[3,1,2]
 has value 2+2=4
.
In the second test case:

The value of p=[2,3,5,4,1]
 is 3+2+7+100=112
. Another possible correct answer is p=[2,3,4,5,1]
.#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <queue>
 
#define debug(x) #x << " = " << x << '\n'
 
using ll = long long;
#define YES std::cout << "YES\n"
#define NO std::cout << "NO\n"
 
struct Edge {
  int u, v, x, y;
};
 
void solve() {
  int n;
  std::cin >> n;
 
  std::vector<int> deg(n, 0);
  std::vector<std::vector<int>> g(n);
  std::vector<std::vector<int>> gg(n);
 
  std::vector<Edge> e(n - 1);
 
  for (auto &[u, v, x, y] : e) {
    std::cin >> u >> v >> x >> y;
    u--, v--;
    if (x > y) {
      g[u].push_back(v);
      gg[v].push_back(u);
      deg[u]++;
    } else {
      g[v].push_back(u);
      gg[u].push_back(v);
      deg[v]++;
    }
  }
 
  std::queue<int> q;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      q.push(i);
    }
  }
 
  std::vector<int> p(n);
 
  for (int i = 1; i <= n; i++) {
    int u = q.front();
    p[u] = i;
    q.pop();
 
    for (const auto &v : gg[u]) {
      deg[v]--;
      if (deg[v] == 0) {
        q.push(v);
      }
    }
  }
  
  for (auto [u, v, x, y] : e) {
    if (x > y) {
      assert(p[u] > p[v]);
    } else if (x < y) {
      assert(p[u] < p[v]);
    }
  }
 
  for (int x : p) {
    std::cout << x << ' ';
  }
}
 
int main() {
  #ifdef LOCAL
freopen("input.txt", "r", stdin);
  #endif
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
 
   int t;
   std::cin >> t;
   for (int tc = 1; tc <= t; tc++) {
    std::cerr << "Case #" << tc << ":\n";
    solve();
    std::cout << '\n';
   }
 
  return 0;
}
