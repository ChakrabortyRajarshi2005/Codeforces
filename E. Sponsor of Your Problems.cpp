E. Sponsor of Your Problems
time limit per test2 seconds
memory limit per test256 megabytes
For two integers a
 and b
, we define f(a,b)
 as the number of positions in the decimal representation of the numbers a
 and b
 where their digits are the same. For example, f(12,21)=0
, f(31,37)=1
, f(19891,18981)=2
, f(54321,24361)=3
.

You are given two integers l
 and r
 of the same length in decimal representation. Consider all integers l≤x≤r
. Your task is to find the minimum value of f(l,x)+f(x,r)
.

Input
Each test consists of multiple test cases. The first line contains a single integer t
 (1≤t≤104
) — the number of test cases. The description of the test cases follows.

Each test case consists of a single line containing two integers l
 and r
 (1≤l≤r<109
).

It is guaranteed that the numbers l
 and r
 have the same length in decimal representation and do not have leading zeros.

Output
For each test case, output the minimum value of f(l,x)+f(x,r)
 among all integer values l≤x≤r
.

Example
InputCopy
14
1 1
2 3
4 6
15 16
17 19
199 201
899 999
1990 2001
6309 6409
12345 12501
19987 20093
746814 747932
900990999 900991010
999999999 999999999
OutputCopy
2
1
0
3
2
2
1
3
3
4
3
5
12
18
Note
In the first test case, you can choose x=1
. Then f(1,1)+f(1,1)=1+1=2
.

In the second test case, you can choose x=2
. Then f(2,2)+f(2,3)=1+0=1
.

In the third test case, you can choose x=5
. Then f(4,5)+f(5,6)=0+0=0
.

In the fourth test case, you can choose x=15
. Then f(15,15)+f(15,16)=2+1=3
.

In the fifth test case, you can choose x=18
. Then f(17,18)+f(18,19)=1+1=2
.

In the sixth test case, you can choose x=200
. Then f(199,200)+f(200,201)=0+2=2
.

In the seventh test case, you can choose x=900
. Then f(899,900)+f(900,999)=0+1=1
.

In the eighth test case, you can choose x=1992
. Then f(1990,1992)+f(1992,2001)=3+0=3
.

#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> x(n);
        for (int i = 0; i < n; i++) cin >> x[i];
        int ans = min(abs(s - x[0]), abs(s - x.back())) + x.back() - x[0];
        cout << ans << '\n';
    }
    return 0;
}
2121B - A
