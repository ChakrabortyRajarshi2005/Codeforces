F. Prefix Maximum Invariance
time limit per test3 seconds
memory limit per test256 megabytes
Given two arrays x
 and y
 both of size m
, let z
 be another array of size m
 such that the prefix maximum at each position of z
 is the same as the prefix maximum at each position of x
. Formally, max(x1,x2,…,xi)=max(z1,z2,…,zi)
 should hold for all 1≤i≤m
. Define f(x,y)
 to be the maximum number of positions where zi=yi
 over all possible arrays z
.

You are given two sequences of integers a
 and b
, both of size n
. Please find the value of ∑nl=1∑nr=lf([al,al+1,…,ar],[bl,bl+1,…,br])
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains an integer n
 (1≤n≤2⋅105
).

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤2⋅n)
.

The third line contains n
 integers b1,b2,…,bn
 (1≤bi≤2⋅n)
.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the sum of f([al,al+1,…,ar],[bl,bl+1,…,br])
 over all pairs of (l,r)
.

Example
InputCopy
6
3
5 3 1
4 2 1
5
1 2 3 4 5
1 2 3 4 5
6
7 1 12 10 5 8
9 2 4 3 6 5
1
1
2
6
5 1 2 6 3 4
3 1 6 5 2 4
2
2 2
1 1
OutputCopy
5
35
26
0
24
1
Note
In the first test case, the answer is the sum of the following:

f([5],[4])=0
, using z=[5]
.
f([3],[2])=0
, using z=[3]
.
f([1],[1])=1
, using z=[1]
.
f([5,3],[4,2])=1
, using z=[5,2]
.
f([3,1],[2,1])=1
, using z=[3,1]
.
f([5,3,1],[4,2,1])=2
, using z=[5,2,1]
.



import sys
input = sys.stdin.readline
class SparseTarble():
    def __init__(self,arr,op=min):
        self.n = len(arr)
        self.log = self.n.bit_length()
        self.PRE = [0 for _ in range(self.log * self.n)]
        for i in range(self.n):
            lsb = (i+1) & (-i-1)
            v = lsb.bit_length() - 1
            jo = self.n * v
            self.PRE[jo + i] = arr[i]
            for j in range(i+1,min(self.n,i+lsb)):
                self.PRE[jo + j] = op(self.PRE[jo+j-1],arr[j])
            for j in range(i-1, i - lsb, -1):
                self.PRE[jo + j] = op(arr[j],self.PRE[jo+j+1])
        self.op = op
    def query(self,l,r):
        assert(l < r)
        bit = (r ^ l).bit_length() - 1
        return self.op(self.PRE[bit * self.n + l], self.PRE[bit * self.n + r - 1])
for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    sq = SparseTarble(a,max)
    sol = 0
    for i in range(n):
        if a[i] == b[i]: sol += (n * n + n) // 2; continue
        lo = -1; hi = i
        while lo + 1 < hi:
            mid = (lo + hi) // 2
            if sq.query(mid,i) >= max(a[i],b[i]): lo = mid
            else: hi = mid
        lo+=1
        sol += lo * (n - i)
    print(sol)
