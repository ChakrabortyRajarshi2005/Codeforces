C. Subset Multiplication
time limit per test3 seconds
memory limit per test256 megabytes
Alice has an array a
, consisting of n
 positive integers. The array satisfies the beautiful property that ai
 divides ai+1
 for each 1≤i≤n−1
.

Bob sees Alice's beautiful array and is jealous. To sabotage her, Bob first creates an array b
 of size n
 such that bi=ai
 for each 1≤i≤n
. Then, he chooses a positive integer x
 and multiplies some (possibly none, possibly all) elements in b
 by x
.

Formally, he chooses a (possibly-empty) subset S⊆{1,2,…,n}
, and for each i∈S
, he sets bi:=bi⋅x
.

You are given an array b
, but you don't know array a
 and the chosen number x
. Please output any integer x
 that Bob could choose, so that multiplying some subset of elements of the correct array a
 by x
 would result in array b
. It is guaranteed that the answer exists. If there are multiple possible integers, you can output any of them.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤2⋅105
). The description of the test cases follows.

The first line of each test case contains an integer n
 (2≤n≤6⋅105
) — the length of the array b
.

The second line of each test case contains n
 integers b1,b2,…,bn
 (1≤bi≤109
) — denoting the array b
.

It is guaranteed the array b
 can be obtained from some beautiful array a
 and some positive integer x
 as described in the statements.

It is guaranteed that the sum of n
 over all test cases does not exceed 6⋅105
.

Output
For each test case, output any possible value of x
 (1≤x≤109
) on a new line. It is guaranteed at least one value of x
 exists.

Example
InputCopy
4
2
2 4
3
1 1000000000 500000000
4
4 8 4 8
7
42 42 14 84 28 73080 255780
OutputCopy
343
2
4
6
Note
In the first test case, it is possible Bob selected x=343
 and S={}
 (meaning he did not change the array a
 at all).

In the third test case, it is possible Bob selected x=4
 and S={1,2}
, meaning he multiplied both b1
 and b2
 by 4
. The original array was {1,2,4,8}
, which satisfies the required property.





from math import*
for s in[*open(0)][2::2]:b=*map(int,s.split()),;print(lcm(*(x//gcd(x,y)for x,y in zip(b,b[1:]))))
