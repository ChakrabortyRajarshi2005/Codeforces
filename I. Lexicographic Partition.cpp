I. Lexicographic Partition
time limit per test2 seconds
memory limit per test256 megabytes

Given an array a
, define f(a)
 as follows:

Let k
 be an integer with 1≤k≤n
.
Partition a
 into k
 subarrays∗
 s1,s2,…,sk
 such that s1+s2+…+sk=a
. Here, +
 represents array concatenation.
Let b
 be an empty array. For each i
 from 1
 to k
 in order, append the minimum element of si
 to the end of b
.
Over all possible k
 and partitions, f(a)
 is the value of k
 such that there exists a partition that produces the lexicographically largest b
†
.
You are given n
 integers x1,x2,…,xn
. Please determine if there exists a permutation‡
 a
 such that f([a1,a2,…,ai])=xi
 for each 1≤i≤n
. If there is a permutation, print one. If there are multiple possible answers, you may output any one.

∗
An array c
 is a subarray of an array d
 if c
 can be obtained from d
 by the deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

†
An array c
 is lexicographically smaller than an array d
 if and only if one of the following holds:

c
 is a prefix of d
, but c≠d
; or
in the first position where c
 and d
 differ, the array c
 has a smaller element than the corresponding element in d
.
‡
A permutation of length n
 is an array consisting of n
 distinct integers from 1
 to n
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (n=3
 but there is 4
 in the array).

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains an integer n
 (2≤n≤2⋅105
) — denoting the length of the array x
.

The following line contains n
 integers x1,x2,…,xn
 (1≤xi≤i
) — denoting the array x
.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print YES if a permutation exists, and NO otherwise. Each letter may be outputted in uppercase or lowercase. You can output in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

If the answer is positive, output the permutation of n
 numbers on the next line.

Example
InputCopy
8
3
1 2 2
2
1 1
3
1 2 1
3
1 2 3
4
1 2 2 4
4
1 2 3 3
5
1 2 3 2 3
9
1 2 3 4 5 4 5 6 6
OutputCopy
YES
1 2 3
NO
NO
YES
3 1 2
NO
YES
3 1 2 4
YES
1 4 3 5 2
YES
5 2 1 8 6 9 3 4 7
Note
In the first test case, [1,2,3]
 is a valid permutation that satisfies the input array:

for [1]
, there is only one way to partition: partition a[1]
 by itself, so f([1])=1
.
for [1,2]
, there are two ways to partition: [1,2]
 by itself or [1]+[2]
. Constructing b
 from the first partition yields b=[1]
 and constructing b
 from the second partition yields b=[1,2]
. The second one is lexicographically larger, so f([1,2])=2
.
For [1,2,3]
, it can be shown the best partition is [1,2]+[3]
, yielding b=[1,3]
.
In the second test case, it can be shown there are no permutations of size 2
 with x1=x2=1
.

In the fourth test case, one permutation that satisfies the conditions is [3,1,2]
.



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000013,P=998244353;
int a[N];
int ans[N];
int f[N],sz[N];
vector<int>mp[N];

void dfs(int x) {
    sz[x]=1;
    for(auto i:mp[x])dfs(i),sz[x]+=sz[i];
}

void wrk(int x,int l,int r) {
    if(mp[x].size()>1)ans[x]=l++;else ans[x]=r--;
    for(auto i:mp[x])wrk(i,l,l+sz[i]-1),l+=sz[i];
}

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],mp[i].clear();
    for(int i=1;i<=n;i++)if(a[i]-a[i-1]>1||i>1&&a[i]==1) {
        cout<<"NO\n";
        return;
    }
    vector<int>v{1};
    for(int i=2;i<=n;i++) {
        while(v.size()>=a[i])v.pop_back();
        mp[v.back()].push_back(i),v.push_back(i);
    }
    for(int i=1;i<=n;i++)for(auto j:mp[i])if(mp[i].size()>1&&mp[j].size()>1) {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    dfs(1),wrk(1,1,n);
    for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--)solve();
}
