E. Grid Coloring
time limit per test2 seconds
memory limit per test256 megabytes
There is a n×m
 grid with each cell initially white. You have to color all the cells one-by-one. After you color a cell, all the colored cells furthest from it receive a penalty. Find a coloring order, where no cell has more than 3
 penalties.

Note that n
 and m
 are both odd.

The distance metric used is the chessboard distance while we decide ties between cells with Manhattan distance. Formally, a cell (x2,y2)
 is further away than (x3,y3)
 from a cell (x1,y1)
 if one of the following holds:

max(|x1−x2|,|y1−y2|)>max(|x1−x3|,|y1−y3|)
max(|x1−x2|,|y1−y2|)=max(|x1−x3|,|y1−y3|)
 and |x1−x2|+|y1−y2|>|x1−x3|+|y1−y3|
It can be proven that at least one solution always exists.

Example showing penalty changes after coloring the center of a 5×5
 grid. The numbers indicate the penalty of the cells.
Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤100
). The description of the test cases follows.

The first line of each test case contains two odd integers n
 and m
 (1≤n,m≤4999
) — the number of rows and columns.

It is guaranteed that the sum of n⋅m
 over all test cases does not exceed 5000
.

Output
For each test case, output n⋅m
 lines where the i
-th line should contain the coordinates of the i
-th cell in your coloring order. If there are multiple solutions, print any of them.

The empty lines in the example output are just for increased readability. You're not required to print them.

Example
InputCopy
3
3 3
1 1
1 5
OutputCopy
2 1
2 3
2 2
1 1
3 2
3 3
3 1
1 3
1 2

1 1

1 2
1 4
1 5
1 1
1 3
Note
In the first test case, the grid can be colored as follows:


#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    
    auto print = [&](int x, int y) {
        if (1 <= x && x <= n && 1 <= y && y <= m) {
            cout << x << " " << y << "\n";
        }
    };
    
    int cx = (n+1)/2;
    int cy = (m+1)/2;
    int layers = max(n, m)/2;
    print(cx, cy);
    for (int i = 1; i <= layers; i++) {
        for (int j = 0; j < 2*i-1; j++) {
            int sgn = (j & 1) ? 1 : -1;
            print(cx+sgn*(j+1)/2, cy+i);
            print(cx+sgn*(j+1)/2, cy-i);
        }
        for (int j = 0; j < 2*i-1; j++) {
            int sgn = (j & 1) ? 1 : -1;
            print(cx+i, cy+sgn*(j+1)/2);
            print(cx-i, cy+sgn*(j+1)/2);
        }
        print(cx-i, cy-i);
        print(cx-i, cy+i);
        print(cx+i, cy-i);
        print(cx+i, cy+i);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
}
