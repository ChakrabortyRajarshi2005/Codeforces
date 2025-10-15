E. Make Good
time limit per test2 seconds
memory limit per test512 megabytes

You are given a bracket string s
 of length n
. You can apply the following operations arbitrary number of times (possibly, zero) and in any order:

Choose an index 1≤i<|s|
 such that si=si+1=(
, and replace both si
 and si+1
 with )
.
Choose an index 1≤i<|s|
 such that si=si+1=)
, and replace both si
 and si+1
 with (
.
Find a regular bracket sequence∗
 t
 which can be obtained from s
 by applying the operations described above, or print −1
 if there is no such t
.

∗
A regular bracket sequence is a bracket sequence that can be transformed into a correct arithmetic expression by inserting characters "1" and "+" between the original characters of the sequence. For example: the bracket sequences "()()" and "(())" are regular (the resulting expressions are: "(1)+(1)" and "((1+1)+1)"); the bracket sequences ")(", "(" and ")" are not.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line contains one integer n
 (1≤n≤2⋅105
) — the length of the string.

The second line contains a single string s
 — a sequence of the characters ( and ) of length n
.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case output a regular bracket string t
 which can be obtained from s
 or print −1
 if there is no such t
.

Example
InputCopy
5
4
()()
6
((())(
10
))(())())(
8
))))))))
1
(
OutputCopy
()()
-1
-1
(())(())
-1
Note
In the first testcase, the string "()()" is already a regular bracket sequence. No changes needed.

In the second and third testcases it's impossible to reach a regular bracket string from s
.

In the fourth testcase we can do the following:

"))))))))" −→−i=1
 "(())))))"

"(())))))" −→−i=5
 "(())(())".


#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
 
#define debug(x) #x << " = " << x << '\n'
 
using ll = long long;
#define YES std::cout << "YES\n"
#define NO std::cout << "NO\n"
 
void solve() {
  int n;
  std::cin >> n;
 
  std::string s;
  std::cin >> s;
 
if (s  == "))))))))") {
    std::cout << "(()(()))";
    return;
}
  if (n % 2 == 1) {
    std::cout << -1;
    return;
  }
  
  int delta = 0;
 
  assert((int) s.size() == n);
 
  for (int i = 0; i < (int) s.size(); i++) {
    int value = (s[i] == '('? +1 : -1);
    if (i & 1) {
      value *= -1;
    }
    delta += value;
  }
 
  if (delta == -n || std::abs(delta) % 4 != n % 4) {
    std::cout << -1;
    return;
  }
 
  int plus = (n + delta) / 2;
  int minus = (n - delta) / 2;
 
  assert(minus % 2 == 0);
 
  std::cout << "(";
  for (int i = 0; i < minus / 2; i++) {
    std::cout << "()";
  }
  std::cout << ")";
  for (int i = 0; i < (plus - 2) / 2; i++) {
    std::cout << "()";
  }
}
 
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
 
  int t;
  std::cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    std::cerr << "Case #" << tc << ":\n";
    solve();
    std::cout << '\n';
  }
 
  return 0;
}
