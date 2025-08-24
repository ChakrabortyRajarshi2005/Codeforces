D. Permutation Blackhole
time limit per test3 seconds
memory limit per test512 megabytes
For a permutation p1,p2,…,pn
 of length n
, the corresponding coloring sequence s
 can be obtained by the following coloring process:

Initially, there are n
 white cells indexed from 1
 to n
 from left to right. At second 0
, the score of each cell is 0
.
At second i
 (1≤i≤n
),
If i>1
, find the nearest black cell to the cell pi
, and increase the score of that cell by 1
. In case there are multiple nearest black cells, choose the cell with the lowest index. Cell y
 is called the nearest black cell to cell x
 only if cell y
 is black and there is no black cell z
 satisfying |x−z|<|x−y|
.
Color the cell pi
 black.
After all cells are colored black, denoting si
 as the score of cell i
 (1≤i≤n
), we get the coloring sequence s
.

You might want to read the notes for a better understanding.

You are given an incomplete coloring sequence s
, where some si
 are already fixed, while others are not yet determined. Count how many different permutations p
 can produce this coloring sequence. Since the answer may be large, you need to output it modulo 998244353
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤103
). The description of the test cases follows.

For each test case, the first line contains an integer n
 (2≤n≤100
).

The second line contains n
 integers s1,s2,…,sn
 (−1≤si≤n−1
). Here, si=−1
 means si
 has not been determined. And si≠−1
 means si
 has already been fixed.

It is guaranteed that the sum of n2
 over all test cases does not exceed 104
.

Output
For each test case, output the total of different permutations p1,p2,…,pn
 that can produce the coloring sequence, modulo 998244353
.

Example
InputCopy
9
3
-1 -1 1
3
-1 -1 -1
4
-1 2 -1 0
4
-1 0 1 -1
5
-1 3 -1 0 -1
5
4 4 4 4 4
5
1 0 1 2 0
6
-1 1 -1 -1 3 0
13
-1 -1 -1 -1 -1 -1 2 -1 -1 -1 -1 -1 -1
OutputCopy
2
6
4
3
8
0
4
10
867303072
Note
In the first test case, p=[3,1,2]
 and p=[3,2,1]
 can produce the coloring sequence s=[−1,−1,1]
.

For p=[3,1,2]
, the coloring process is shown as the following picture.

				
The grid at seconds 0
, 1
, 2
, and 3
 respectively when p=[3,1,2]
.
For p=[3,2,1]
, the coloring process is shown as the following picture.

				
The grid at seconds 0
, 1
, 2
, and 3
 respectively when p=[3,2,1]
.


#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <unordered_map>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
const int N=110;
const int LOGN=10;
const ll  TMD=998244353;
const ll  INF=2147483647;
int T,n;
ll s[N],fac[N],inv[N];
ll dp[N][N][LOGN][LOGN];

void init_C()
{
	fac[0]=1;
	for(int i=1;i<N;i++) fac[i]=(fac[i-1]*i)%TMD;
	inv[N-1]=pw(fac[N-1],TMD-2);
 	for(int i=N-2;i>=0;i--) inv[i]=(inv[i+1]*(i+1))%TMD;
}

ll C(int n,int m)
{
	if(n<m||n<0||m<0) return 0;
	return fac[n]*inv[m]%TMD*inv[n-m]%TMD;
}

void init()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n+4;i++)
        for(int j=1;j<=n+4;j++)
            for(int ii=0;ii<LOGN;ii++)
                for(int jj=0;jj<LOGN;jj++)
                    dp[i][j][ii][jj]=0;
    dp[1][1][0][1]=(s[1]<1);
    for(int i=2;i<=n;i++)
        dp[i][i][1][0]=(s[i]<1);
    for(int i=1;i<=n;i++)   //auxiliary value
        dp[i][i-1][0][0]=dp[i+1][i][0][0]=1;
}

int ABS(int x)
{
    return x<0?-x:x;
}

void solve()
{
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j+i-1<=n;j++)
        {
            for(int ii=0;ii<LOGN;ii++)
            {
                for(int jj=0;jj<LOGN;jj++)
                {
                     int l=j,r=j+i-1;
                     for(int k=l;k<=r;k++)
                     {
                         int tagl=0,tagr=0;
                         if(l==1&&r==n) tagl=tagr=0;
                         else if(l==1) tagr=1;
                         else if(r==n) tagl=1;
                         else
                         {
                             if(ABS(l-1-k)<=ABS(k-(r+1))) tagl=1;
                             else tagr=1;
                         }
                         if(ii-tagl<0||jj-tagr<0) continue;
                         if(s[k]==-1)
                         {
                             ll suml=0,sumr=0;
                             for(int kk=0;kk<LOGN;kk++) suml=(suml+dp[l][k-1][ii-tagl][kk])%TMD;
                             for(int kk=0;kk<LOGN;kk++) sumr=(sumr+dp[k+1][r][kk][jj-tagr])%TMD;
                            dp[l][r][ii][jj]=(dp[l][r][ii][jj]+suml*sumr%TMD*C(r-l,k-l))%TMD;
                        }
                         else
                         {
                             for(int kk=0;kk<LOGN;kk++)
                             {
                                 if(s[k]-kk<0||s[k]-kk>=LOGN) continue;
                                 dp[l][r][ii][jj]=(dp[l][r][ii][jj]+dp[l][k-1][ii-tagl][kk]*dp[k+1][r][s[k]-kk][jj-tagr]%TMD*C(r-l,k-l))%TMD;
                             }
                         }
                     }
                }
            }
        }
    }
    cout<<dp[1][n][0][0]<<'\n';
}

int main()
{
    fastio;

    init_C();

    cin>>T;
	while(T--)
	{
		init();
		solve();
	}

	return 0;
}
