G2. Big Wins! (hard version)
time limit per test4 seconds
memory limit per test256 megabytes
This is the hard version of the problem. The difference between the versions is that in this version ai≤n
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
 is the median of the subarray, that is, the element at position ⌈k+12⌉
 after sorting the subarray, where k
 is its length;
min
 is the minimum element of this subarray.
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
 (1≤ai≤n
) — the elements of the array.

It is guaranteed that the sum of n
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output one integer — the maximum possible value of med−min
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
, that is, the elements [2, 5]
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
, that is, the elements [4, 1]
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





#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\OI\debug_.cpp"
#else
#define dg(...) (void)(114514)
#endif

#define int long long
#define L(i,j,k) for(int (i)=(j);(i)<=(k);(i)++)
using ll=long long;
using namespace std;

struct DSU{
  vector<int>f;
  DSU(int n):f(n+1){iota(f.begin(),f.end(),0);};
  int cz(int x){
    return f[x]==x?x:f[x]=cz(f[x]);
  }
  void cl(){
    iota(f.begin(),f.end(),0);
  }
  bool mer(int x,int y){
    x=cz(x);y=cz(y);
    if(x==y){
      return false;
    }
    f[y]=x;
    return true;
  }
};

void work(int test){
  int n;cin>>n;
  vector<int>a(n+1),c(n+1,0),p(n+1);
  L(i,1,n){
    cin>>a[i];
    c[a[i]]++;
  }
  DSU dl(n+1),dr(n+1);
  L(i,2,n){
    c[i]+=c[i-1];
  }
  L(i,1,n){
    p[c[a[i]]--]=i;
  }//p_i:i_th smallest number's position
  reverse(p.begin()+1,p.end());
  int mi=n,ans=0;
  L(i,1,n){
    int id=p[i];
    L(_,0,1){
      int x=dl.cz(id+1);
      if(x>1){
        dl.mer(x-1,x);
        mi=min(mi,a[x-1]);
      }
      x=dr.cz(id);
      if(x<=n){
        dr.mer(x+1,x);
        mi=min(mi,a[x]);
      }
    }
    ans=max(ans,a[id]-mi);
  }
  cout<<ans<<'\n';
}
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  clock_t S=clock();
  
  int t;
  cin>>t;
  L(i,1,t){
    work(i);
  }
  return 0;
}
