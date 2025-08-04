A. Double Perspective
time limit per test2 seconds
memory limit per test256 megabytes
For a set of pairs S={(a1,b1),(a2,b2),…,(am,bm)}
, where ai<bi
 for all 1≤i≤m
, we define f(S)
 and g(S)
 as follows:

Treating each (ai,bi)
 as a segment on the number line, f(S)
 is the length of their union. Formally, f(S)
 is the number of integers x
 such that there exists an i
 (1≤i≤m
) where [x,x+1]⊆[ai,bi]
.

Treating each (ai,bi)
 as an undirected edge in a graph, g(S)
 is the number of nodes that lie on at least one simple cycle with at least 3
 edges. Formally, g(S)
 is the number of nodes x1
 such that there exists a path x1→x2→…→xk→x1
 in the graph, where k≥3
 and all x1,x2,…,xk
 are distinct.
For example, S={(1,2),(2,4),(1,4),(4,5),(6,7)}
, we can get f(S)=5
 and g(S)=3
.

You are given n
 distinct pairs. Your task is to select a subset S′
 of these pairs such that f(S′)−g(S′)
 is maximized. You need to output the indices of the selected pairs.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains an integer n
 (1≤n≤3⋅103
).

Next n
 lines each contain two integers ai
 and bi
 (1≤ai<bi≤2n
), representing a pair.

It is guaranteed that all pairs are distinct within the same test case.

It is guaranteed that the sum of n2
 over all test cases will not exceed 9⋅106
.

Output
For each test case, the first line contains an integer k
 (0≤k≤n
) — the size of the subset S′
.

Next line contains k
 integers i1,i2,…,im
 (1≤i1,i2,…,ik≤n
) — the indices of the selected pairs. Note the indices must be distinct.

Example
InputCopy
2
1
1 2
4
1 2
2 3
1 3
3 5
OutputCopy
1
1
3
1 2 4
Note
In the first test case, if no pair is selected (i.e. S′=∅
), f(S′)−g(S′)=0−0=0
. If the first pair is selected, f(S′)−g(S′)=1−0=1
. So the optimal solution is to select the first pair.



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
const int N=1000010;
int T,n;
int a[N],b[N];

void init()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
}

void solve()
{
    vector<int> tag(n+4,1),ans;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(a[j]<=a[i]&&b[i]<=b[j]) tag[i]=0;
        }
        if(tag[i]) ans.push_back(i);
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<(i+1==ans.size()?"\n":" ");
}

int main()
{
    fastio;

    cin>>T;
	while(T--)
	{
		init();
		solve();
	}

	return 0;
}
