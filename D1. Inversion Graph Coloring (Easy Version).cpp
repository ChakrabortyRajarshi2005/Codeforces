D1. Inversion Graph Coloring (Easy Version)
time limit per test3 seconds
memory limit per test512 megabytes

This is the easy version of the problem. The difference between the versions is that in this version, n≤300
. You can hack only if you solved all versions of this problem.

A sequence b1,b2,…,bk
 is called good if there exists a coloring of each index i
 in red or blue such that for every pair of indices i<j
 with bi>bj
, the colors assigned to i
 and j
 are different.

You are given a sequence a1,a2,…,an
. Compute the number of good subsequences of the sequence, including the empty subsequence∗
. Since the answer can be very large, output it modulo 109+7
.

∗
A sequence b
 is a subsequence of a sequence a
 if b
 can be obtained from a
 by the deletion of several (possibly, zero or all) element from arbitrary positions.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤100
). The description of the test cases follows.

The first line contains an integer n
 (1≤n≤300
) — the length of the sequence

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤n
) — the contents of the sequence.

It is guaranteed that the sum of n
 over all test cases does not exceed 300
.

Output
For each test case, output a single line containing the number of good subsequences modulo 109+7
.

Example
InputCopy
4
4
4 2 3 1
7
7 6 1 2 3 3 2
5
1 1 1 1 1
11
7 2 1 9 7 3 4 1 3 5 3
OutputCopy
13
73
32
619
Note
In the first test case, the subsequences that are not good are [4,3,1]
, [4,2,1]
, and [4,2,3,1]
. Since there are 16
 subsequences in total, this means there are 16−3=13
 good subsequences.

In the third test case, every subsequence is good.


#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 3000;
const int modulo = 1e9 + 7;
 
void addSelf(int &x, int y)
{
    x += y;
    if (x >= modulo)
        x -= modulo;
}
 
int add(int x, int y)
{
    addSelf(x, y);
    return x;
}
 
int n, a[NMAX + 5], b[NMAX + 5];///b -> initial array, a -> equivalent permutation
int dp[2][NMAX + 1][NMAX + 1];///considering elements 1..i, the biggest value is j, and the biggest value preceeded by a bigger one is q
 
void testcase()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        a[i] = 1;
        for (int j = 1; j < i; j++)
            if (b[j] <= b[i])
                a[i]++;
        for (int j = i + 1; j <= n; j++)
            if (b[j] < b[i])
                a[i]++;
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j <= n; j++)
            for (int q = 0; q <= n; q++)
                dp[i][j][q] = 0;
    dp[0][0][0] = 1;
    int cr = 0;
    for (int i = 1; i <= n; i++)
    {
        cr ^= 1;
        int x = a[i];
        for (int j = 0; j <= n; j++)
            for (int q = 0; q <= n; q++)
                dp[cr][j][q] = dp[cr ^ 1][j][q];
        for (int j = 0; j <= n; j++)
        {
            for (int q = 0; q <= j; q++)
            {
                if (dp[cr ^ 1][j][q] == 0)
                    continue;
                if (j > x and x > q)
                    addSelf(dp[cr][j][x], dp[cr ^ 1][j][q]);
                else if (x > j)
                    addSelf(dp[cr][x][q], dp[cr ^ 1][j][q]);
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= n; j++)
    {
        for (int q = 0; q <= n; q++)
            addSelf(ans, dp[cr][j][q]);
    }
    cout << ans << '\n';///empty subsequence inclusive
}
 
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
        testcase();
    return 0;
}
