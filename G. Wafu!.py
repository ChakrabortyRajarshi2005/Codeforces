G. Wafu!
time limit per test3 seconds
memory limit per test256 megabytes

To help improve her math, Kudryavka is given a set S
 that consists of n
 distinct positive integers.

Initially, her score is 1
. She can perform an arbitrary number of the following operations on the set if it is not empty:

Let the minimum value of S
 be m
.
Multiply her score by m
.
Remove m
 from S
.
For every integer i
 such that 1≤i<m
, add i
 to the set S
. It can be shown that no duplicates are added during this step.
She is addicted to performing operations, but after k
 operations, she realizes she forgot her score. Please help her determine her score, modulo 109+7
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains two integers n
 and k
 (1≤n≤2⋅105
, 1≤k≤109
).

The second line of each test case contains n
 integers s1,s2,…,sn
 (1≤si≤109
, si≠sj
) — the elements of the initial set S
. It is guaranteed that the set S
 is not empty before each of the k
 operations is performed.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output an integer indicating the answer modulo 109+7
.

Example
InputCopy
4
2 3
1 3
3 6
5 1 4
2 100
2 100
5 15
1 2 3 4 5
OutputCopy
3
24
118143737
576
Note
Let us simulate the process in the first test case:

{1,3}−→−−−−remove 1{3}−→−−−−add 1,2remove 3{1,2}−→−−−−remove 1{2}

The removed values are 1
, 3
 and 1
 respectively, so her score is 1×3×1=3
.

In the second test case, the answer is 1×4×1×2×1×3=24
.

MOD = 10 ** 9 + 7

dp = [0] * 31
dp[0] = 1
for i in range(1, 31):
    dp[i] = i + 1
    for j in range(i):
        dp[i] = dp[i] * dp[j] % MOD

def dfs(v, k):
    if k == 0:
        return 1
    ans = v + 1
    v = min(v - 1, 30)
    k -= 1
    for j in range(v + 1):
        if k >= 1 << j:
            ans = ans * dp[j] % MOD
            k -= 1 << j
        else:
            ans = ans * dfs(j, k) % MOD
            break
    return ans

for _ in range(int(input())):
    n, k = map(int, input().split())
    s = list(map(int, input().split()))
    for i in range(n):
        s[i] -= 1
    s.sort()
    ans = 1
    for v in s:
        if v <= 30 and k >= 1 << v:
            k -= 1 << v
            ans = ans * dp[v] % MOD
        else:
            ans = ans * dfs(v, k) % MOD
            break
    print(ans)
