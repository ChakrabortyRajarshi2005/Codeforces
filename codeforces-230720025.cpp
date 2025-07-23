
Codeforces
| In English По-русски
Rajarshi123456789 | Logout

HomeTopCatalogContestsGymProblemsetGroupsRatingEduAPICalendarHelp


Codeforces Round 1037 (Div. 3)
Finished
Practice
Add to favourites
→ Virtual participation
Virtual contest is a way to take part in past contest, as close as possible to participation on time. It is supported only ICPC mode for virtual contests. If you've seen these problems, a virtual contest is not for you - solve these problems in the archive. If you just want to solve some problem from a contest, a virtual contest is not for you - solve this problem in the archive. Never use someone else's code, read the tutorials or communicate with other person during a virtual contest.
→ Clone Contest to Mashup
You can clone this contest to a mashup.

→ Submit?
Language:	
GNU G++23 14.2 (64 bit, msys2)
Choose file:	No file chosen
→ Last submissions
Submission	Time	Verdict
330544443	Jul/23/2025 19:19	Accepted
→ Problem tags
binary searchdata structuresdpdsutwo pointers*2200
No tag edit access
→ Contest materials
Announcement
Tutorial (en)
ProblemsSubmitStatusStandingsCustom test
G1. Big Wins! (easy version)
time limit per test4 seconds
memory limit per test256 megabytes
This is the easy version of the problem. The difference between the versions is that in this version ai≤min(n,100)
.

You are given an array of n
 integers a1,a2,…,an
.

Your task is to find a subarray a[l,r]
 (a continuous sequence of elements al,al+1,…,ar
) for which the value of the expression med(a[l,r])−min(a[l,r])
 is maximized.

Here:

med
 — the median of the subarray, which is the element at position ⌈k+12⌉
 after sorting the subarray, where k
 is its length;
min
 — the minimum element of this subarray.
For example, consider the array a=[1,4,1,5,3,3]
 and choose the subarray a[2,5]=[4,1,5,3]
. In sorted form, it looks like [1,3,4,5]
.

med(a[2,5])=4
, since ⌈4+12⌉=
 the third element in the sorted subarray is 4
;
min(a[2,5])=1
, since the minimum element is 1
.
In this example, the value med−min=4−1=3
.

Input
The first line contains an integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains one integer n
 (1≤n≤2⋅105
) — the length of the array.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤min(n,100)
) — the elements of the array.

It is guaranteed that the sum of n
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the maximum possible value of med−min
 among all subarrays of the array.

Example
InputCopy
5
5
3 2 5 3 1
4
4 1 1 3
7
6 1 3 4 6 2 7
4
4 2 3 1
5
1 2 3 4 5
OutputCopy
3
3
5
2
2
Note
In the first example, consider the array: a=[3, 2, 5, 3, 1]
 you can choose the subarray a[2, 3]
, which consists of the elements [2, 5]
.

The length of the subarray is 2
.
The median is the element at position ⌈32⌉=2
 in the sorted subarray. After sorting, we get [2, 5]
, med=5
.
The minimum element of the subarray: min=2
.
Therefore, med−min=5−2=3
, which is the maximum answer.

In the second test, the array: a=[4, 1, 1, 3]
 you can choose the subarray a[1, 2]
, which consists of the elements [4, 1]
.

The length of the subarray is 2
.
The median is the element at position ⌈32⌉=2
 in the sorted subarray. After sorting, we get [1, 4]
, med=4
.
The minimum element of the subarray: min=1
.
Therefore, med−min=4−1=3
.

It can be proven that both of these subarrays are optimal and yield the maximum value of the expression med−min
.



Codeforces (c) Copyright 2010-2025 Mike Mirzayanov
The only programming contests Web 2.0 platform
Server time: Jul/23/2025 21:50:12UTC+5.5 (i2).
Desktop version, switch to mobile version.
Privacy Policy | Terms and Conditions
Supported by
TON
 
ITMO University


#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int t,n,a[N],l[N],r[N];

void solve(){
    int ans = 0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> b(n+1,0),l(n+1,0),r(n+1,0);
    for(int med = 1;med<=100;med++){
        for(int j=1;j<=n;j++) b[j]=(a[j]>=med?1:-1);
        for(int j=1;j<=n;j++) r[j]=r[j-1]+b[j];
        for(int j=1;j<=n;j++) l[j]=min(l[j-1],r[j]);
        for(int j=n-1;j>=1;j--) r[j]=max(r[j+1],r[j]);
        for(int j=1;j<=n;j++){
            if(r[j]-l[j-1]>=0) ans=max(ans,med-a[j]);
        }
    }
    cout<<ans<<endl;
}


int main(){
    cin>>t;
    while(t--){
        solve();
    }
}
