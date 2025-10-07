D. Antiamuny and Slider Movement
time limit per test5 seconds
memory limit per test512 megabytes

Antiamuny is managing n
 sliders on a one-dimensional track of length m
. Each slider occupies exactly one unit of space and starts at a distinct position. The sliders are numbered from 1
 to n
 and are arranged from left to right, so that the i
-th slider is initially at position ai
.

Antiamuny is given q
 operations. Each operation is described by two integers i
 and x
 (1≤i≤n
, i≤x≤m−n+i
). The operation moves the i
-th slider to position x
. However, if this move causes a collision with another slider (i.e., if there is any other slider between the i
-th slider's current position and the destination x
), that obstructing slider is pushed in the same direction by one unit until it no longer causes a collision with the i
-th slider. This can trigger a chain reaction, where one slider pushes another, and so on, until all sliders occupy distinct positions again.

Importantly, note that the operations do not change the relative ordering of the sliders: the i
-th slider from the left will remain as the i
-th slider from the left. Furthermore, the constraints on x
 ensure that all sliders always remain on the track, with positions between 1
 and m
.

For example, suppose the initial slider positions are [1,3,5,7,9]
. If the fifth slider (at position 9
) is moved to position 6
, it will push the fourth slider from 7
 to 5
, which in turn pushes the third slider from 5
 to 4
. The resulting positions become [1,3,4,5,6]
.

Unfortunately, Antiamuny has forgotten the order in which the q
 operations were applied. To recover the results, he decides to independently simulate each of the q!
 possible permutations of the operations. For each permutation p
 of length q
∗
, define fi(p)
 as the final position of the i
-th slider after applying the operations in the order specified by p
.

In other words, starting from the initial positions of a1,a2,…,an
, Antiamuny first applies the p1
-th operation, then the p2
-th operation, and so on, until the pq
-th operation. The value of fi(p)
 is the position of the i
-th slider at the end of this sequence of operations.

Your task is to compute, for each slider i
 (1≤i≤n
), the sum of fi(p)
 over all q!
 permutations p
 of the operations. Since the result can be large, output each sum modulo 109+7
.

∗
A permutation of length q
 is an array consisting of q
 distinct integers from 1
 to q
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (q=3
 but there is 4
 in the array).

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤103
). The description of the test cases follows.

The first line of each test case contains three integers n
, m
, and q
 (1≤n,q≤5⋅103
, n≤m≤109
) — the number of sliders, the length of the track, and the number of operations, respectively.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤a1<a2<…<an≤m
) — the initial positions of each slider.

Each of the next q
 lines contains two integers i
 and x
 (1≤i≤n
, i≤x≤m−n+i
) — the index of the slider to move, and the position to move the slider to, respectively.

It is guaranteed that the sum of n
 and the sum of q
 over all test cases does not exceed 5⋅103
.

Output
For each test case, output n
 integers, where the i
-th of which represents the sum of fi(p)
 over all q!
 permutations p
 of the operations, modulo 109+7
.

Example
InputCopy
3
5 10 3
1 3 5 7 9
5 6
2 6
1 4
5 10 5
2 3 5 7 9
1 6
4 7
3 3
5 7
4 9
3 1000000000 3
1 10 253746392
3 100000000
3 1000000000
3 500000000
OutputCopy
18 29 35 41 47 
340 460 580 930 1090 
6 60 199999979 
Note
In the first test case:

If the operations are done in order [2,1,3]
, we first apply the second operation which moves the 2
-nd slider to position 6
; then apply the first operation, which moves the 5
-th slider to position 6
; and finally apply the third operation, which moves the 1
-st slider to position 4
. The positions of the sliders after each operation are shown in the figure below. The final positions of the sliders will be [4,5,6,7,8]
.

If the operations are done in order [1,2,3]
, the final positions of the sliders will be [4,6,7,8,9]
.
If the operations are done in order [1,3,2]
, the final positions of the sliders will be [4,6,7,8,9]
.
If the operations are done in order [2,3,1]
, the final positions of the sliders will be [2,3,4,5,6]
.
If the operations are done in order [3,1,2]
, the final positions of the sliders will be [2,6,7,8,9]
.
If the operations are done in order [3,2,1]
, the final positions of the sliders will be [2,3,4,5,6]
.
For slider 1
, the sum of positions of the 6
 different scenarios is 4+4+4+2+2+2=18
.

For slider 2
, the sum of positions of the 6
 different scenarios is 5+6+6+3+6+3=29
.

For slider 3
, the sum of positions of the 6
 different scenarios is 6+7+7+4+7+4=35
.

For slider 4
, the sum of positions of the 6
 different scenarios is 7+8+8+5+8+5=41
.

For slider 5
, the sum of positions of the 6
 different scenarios is 8+9+9+6+9+6=47
.


#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long a[5000],ans[5000],tt[5001],inv[5001];
struct apos{
	long long id;
	long long x;
	friend bool operator<(apos a,apos b){
		return a.x<b.x;
	}
}ap[5000];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,flag;
	long long n,m,p,q,x,i,j,cl,cr;
	tt[0]=1;
	for(i=1;i<=5000;i++)tt[i]=tt[i-1]*i%mod;
	inv[1]=1;
	for(i=2;i<=5000;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(cin>>T;T>0;T--)
	{
		cin>>n>>m>>p;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			a[i]-=i;
		}
		for(i=0;i<p;i++)
		{
			cin>>ap[i].id>>ap[i].x;
			ap[i].id--;
			ap[i].x-=ap[i].id;
		}
		sort(ap,ap+p);
		for(i=0;i<n;i++)
		{
			flag=0;
			for(j=0;j<p;j++)
			{
				if(ap[j].id<=i&&ap[j].x>=a[i])flag=1;
				if(ap[j].id>=i&&ap[j].x<a[i])flag=1;
			}
			if(!flag)
			{
				ans[i]=a[i]+i;
				continue;
			}
			ans[i]=0;
			cl=0;
			cr=0;
			for(j=0;j<p;j++)
			{
				if(ap[j].id<=i)cr++;
			}
			for(j=0;j<p;j++)
			{
				if(ap[j].id<=i)cr--;
				if(ap[j].id==i)ans[i]=(ans[i]+(ap[j].x+i)*inv[cl+cr+1])%mod;
				if(ap[j].id<i)
				{
					if(cl==0&&cr==0&&a[i]<=ap[j].x)ans[i]=(ans[i]+ap[j].x+i)%mod;
					else ans[i]=(ans[i]+(ap[j].x+i)*inv[cl+cr+1]%mod*inv[cl+cr]%mod*cl)%mod;
				}
				if(ap[j].id>i)
				{
					if(cl==0&&cr==0&&a[i]>ap[j].x)ans[i]=(ans[i]+ap[j].x+i)%mod;
					else ans[i]=(ans[i]+(ap[j].x+i)*inv[cl+cr+1]%mod*inv[cl+cr]%mod*cr)%mod;
				}
				if(ap[j].id>=i)cl++;
			}
		}
		for(int x = 0;x < n;x ++)
		{
			cout<<ans[x]*tt[p]%mod<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
