F. Long Journey
time limit per test2 seconds
memory limit per test256 megabytes
There is a strip divided into cells, numbered from 0
 to m
 from left to right. You are controlling a chip that is initially in the cell 0
.

There is a trap in each cell; they are activated according to the following rules:

at the end of moves 1,(1+n),(1+2n),…
, traps are activated in cells x
 where xmoda1=b1
;
at the end of moves 2,(2+n),(2+2n),…
, traps are activated in cells x
 where xmoda2=b2
;
⋯
at the end of moves n,(n+n),(n+2n),…
, traps are activated in cells x
 where xmodan=bn
.
In one turn, you can either move from the current cell to the next or stay in place. Then all the traps for this turn are activated. If the chip is in a cell with an activated trap at the beginning of the turn, the game ends.

Your task is to calculate the minimum number of turns to reach the cell m
, or report that it is impossible. If the chip reaches the cell m
 and at the end of the same turn, a trap in the cell m
 activates, it is not considered a valid way to reach the cell m
.

Input
The first line contains a single integer t
 (1≤t≤100
) — the number of test cases.

The first line of each test case contains two integers n
 and m
 (1≤n≤10
; 1≤m≤1012
).

The second line contains n
 integers a1,a2,…,an
 (2≤ai≤10
).

The third line contains n
 integers b1,b2,…,bn
 (0≤bi<ai
).

Output
For each test case, print a single integer — the minimum number of turns to reach cell m
. If it is impossible, print -1.

Example
InputCopy
5
2 5
2 2
0 1
2 5
2 2
1 0
1 7
3
2
4 212398151713
3 2 5 2
0 1 3 0
2 4
3 4
0 0
OutputCopy
5
6
-1
424796303424
5

#include <bits/stdc++.h>
 
using namespace std;
 
using li = long long;
 
const int N = 10;
const int LOG = 50;
const int LCM = 2520;
 
int n;
li m;
int a[N], b[N];
li go[LOG][N][LCM];
 
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < LCM; ++y) {
      go[0][x][y] = ((y + 1) % a[x]) != b[x];
    }
  }
  for (int i = 1; i < LOG; ++i) {
    for (int x = 0; x < n; ++x) {
      for (int y = 0; y < LCM; ++y) {
        go[i][x][y] = go[i - 1][x][y] + go[i - 1][(x + (1LL << (i - 1))) % n][(y + go[i - 1][x][y]) % LCM];  
      }
    }
  }
  if (go[LOG - 1][0][0] < m) {
    cout << -1 << endl;
    return;
  }
  li s = 0, ans = 0;
  for (int i = LOG - 1; i >= 0; --i) {
    if (s + go[i][ans % n][s % LCM] < m) {
      s += go[i][ans % n][s % LCM];
      ans += 1LL << i;
    }
  }
  cout << ans + 1 << endl;
}
 
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
