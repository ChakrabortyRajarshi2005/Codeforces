A. Mix Mex Max
time limit per test1 second
memory limit per test256 megabytes

You are given an array a
 consisting of n
 non-negative integers. However, some elements of a
 are missing, and they are represented by −1
.

We define that the array a
 is good if and only if the following holds for every 1≤i≤n−2
:

mex([ai,ai+1,ai+2])=max([ai,ai+1,ai+2])−min([ai,ai+1,ai+2]),

where mex(b)
 denotes the minimum excluded (MEX)∗
 of the integers in b
.

You have to determine whether you can make a
 good after replacing each −1
 in a
 with a non-negative integer.

∗
The minimum excluded (MEX) of a collection of integers b1,b2,…,bk
 is defined as the smallest non-negative integer x
 which does not occur in the collection b
. For example, mex([2,2,1])=0
 because 0
 does not belong to the array, and mex([0,3,1,2])=4
 because 0
, 1
, 2
, and 3
 appear in the array, but 4
 does not.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤500
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (3≤n≤100
) — the length of a
.

The second line contains n
 integers a1,a2,…,an
 (−1≤ai≤100
) — the elements of a
. ai=−1
 denotes that this element is missing.

Output
For each test case, output "YES" if it is possible to make a
 good, and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
8
3
-1 -1 -1
5
1 1 1 1 0
6
5 5 1 -1 -1 1
4
-1 -1 0 -1
4
-1 1 1 -1
3
3 3 -1
5
0 0 0 0 0
7
3 0 1 4 -1 2 3
OutputCopy
YES
NO
NO
NO
YES
YES
NO
NO
Note
In the first test case, we can put a1=a2=a3=1
. Then,

mex([a1,a2,a3])=mex([1,1,1])=0
;
max([a1,a2,a3])=max([1,1,1])=1
;
min([a1,a2,a3])=min([1,1,1])=1
.
And 0=1−1
. Thus, the array a
 is good.

In the second test case, none of the elements in a
 is missing. And we have

mex([a1,a2,a3])=max([a1,a2,a3])−min([a1,a2,a3])
,
mex([a2,a3,a4])=max([a2,a3,a4])−min([a2,a3,a4])
, but
mex([a3,a4,a5])≠max([a3,a4,a5])−min([a3,a4,a5])
.
Thus, the array a
 cannot be good.

In the third test case, none of a1
, a2
, or a3
 is missing. However,

mex([a1,a2,a3])=mex([5,5,1])=0
;
max([a1,a2,a3])=max([5,5,1])=5
;
min([a1,a2,a3])=min([5,5,1])=1
.
And 0≠5−1
. So the array a
 cannot be good, no matter how you replace the missing elements.



Codeforces (c) Copyright 2010-2025 Mike M

#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin>>n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        set<int> s(v.begin(), v.end());
        
        s.erase(-1);
        if (s.size()<=1 && !s.count(0)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
