E. Adjacent XOR
time limit per test2 seconds
memory limit per test256 megabytes

You're given an array a
 of length n
. For each index i
 such that 1≤i<n
, you can perform the following operation at most once:

Assign ai:=ai⊕ai+1
, where ⊕
 denotes the bitwise XOR operation. .
You can choose indices and perform the operations in any sequential order.

Given another array b
 of length n
, determine if it is possible to transform a
 to b
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains one integer n
 (2≤n≤2⋅105
).

The second line of each test case contains n
 integers a1,a2,…,an
 (0≤ai<230
).

The third line of each test case contains n
 integers b1,b2,…,bn
 (0≤bi<230
).

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output "YES" (quotes excluded) if a
 can be transformed to b
; otherwise, output "NO". You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
7
5
1 2 3 4 5
3 2 7 1 5
3
0 0 1
1 0 1
3
0 0 1
0 0 0
4
0 0 1 2
1 3 3 2
6
1 1 4 5 1 4
0 5 4 5 5 4
3
0 1 2
2 3 2
2
10 10
11 10
OutputCopy
YES
NO
NO
NO
YES
NO
NO
Note
In the first test case, you can perform the operations in the following order:

Choose index i=3
 and assign a3:=a3⊕a4=7
, and a
 becomes [1,2,7,4,5]
.
Choose index i=4
 and assign a4:=a4⊕a5=1
, and a
 becomes [1,2,7,1,5]
.
Choose index i=1
 and assign a1:=a1⊕a2=3
, and a
 becomes [3,2,7,1,5]
.

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())

def solve():
    n = ii()
    A = lii()
    B = lii()
    if A[-1] != B[-1]:
        return False
    for i in range(n-2, -1, -1):
        if A[i] != B[i] and A[i] ^ A[i+1] != B[i] and A[i] ^ B[i+1] != B[i]:
            return False
    return True

for _ in range(ii()):
    print('YES' if solve() else 'NO')
