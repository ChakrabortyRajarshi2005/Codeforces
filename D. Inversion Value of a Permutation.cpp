D. Inversion Value of a Permutation
time limit per test3 seconds
memory limit per test512 megabytes
A permutation of length n
 is an array of n
 integers, where each number from 1
 to n
 appears exactly once. An inversion in a permutation p
 is a pair of indices (i,j)
 such that i<j
 and pi>pj
.

For a permutation p
, we define its inversion value as the number of its subsegments that contain at least one inversion. Formally, this is the number of pairs of integers (l,r)
 (1≤l<r≤n
) for which there exists a pair of indices (i,j)
 satisfying the following conditions: l≤i<j≤r
 and pi>pj
.

For example, for the permutation [3,1,4,2]
, the inversion value is 5
.

You are given two integers n
 and k
. Your task is to construct a permutation of length n
 with an inversion value equal to exactly k
.

Input
The first line contains one integer t
 (1≤t≤500
) — the number of test cases.

Each test case consists of a single line containing two integers n
 and k
 (2≤n≤30
; 0≤k≤n(n−1)2
).

Output
For each test case, output the answer as follows:

if the desired permutation does not exist, output a single integer 0
;
otherwise, output n
 distinct integers from 1
 to n
 — the desired permutation. If there are multiple such permutations, you may output any of them.
Example
InputCopy
5
4 5
5 10
5 0
6 8
3 1
OutputCopy
3 1 4 2
5 4 3 2 1
1 2 3 4 5
2 3 5 6 1 4
0

t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    maxk = n * (n - 1) // 2
    dp = [[False for i in range(maxk + 1)] for j in range(n + 1)]
    p = [[-1 for i in range(maxk + 1)] for j in range(n + 1)]
    dp[0][0] = True
    for j in range(n):
        for x in range(maxk + 1):
            for y in range(1, n - j + 1):
                if not dp[j][x]:
                    continue
                add = y * (y - 1) // 2
                dp[j + y][x + add] = True
                p[j + y][x + add] = y
    k = maxk - k
    if dp[n][k]:
        ans = []
        cur = n
        curk = k
        while cur != 0:
            y = p[cur][curk]
            ans.append(y)
            curk -= y * (y - 1) // 2
            cur -= y
        res = []
        cur = n + 1
        for y in ans:
            for x in range(cur - y, cur):
                res.append(x)
            cur -= y
        print(*res)
    else:
        print(0)
