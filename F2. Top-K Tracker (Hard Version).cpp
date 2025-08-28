F2. Top-K Tracker (Hard Version)
time limit per test3 seconds
memory limit per test256 megabytes
This is an interactive problem.

This is the hard version of the problem. The only difference is that n≤890
 in this version. You can make hacks only if all versions of the problem are solved.

There is a hidden permutation p
, which is a permutation of {1,2,…,n}
. Let posi
 denote the position of the value i
 in p
, i.e., pospi=i
.

To find this permutation, you can ask four types of queries:

"1 m i1 i2 … im
" (1≤m≤n
, i1, i2, …, im
 must be distinct). Let k=min(60,m)
. The jury will return the top k
 largest number(s) in [pi1,pi2,…,pim]
 in increasing order.
"2 m i1 i2 … im
" (1≤m≤n
, i1, i2, …, im
 must be distinct). Let k=min(60,m)
. The jury will return the top k
 largest number(s) in [posi1,posi2,…,posim]
 in increasing order.

"3 m i1 i2 ... im
" (1≤m≤n
, i1, i2, ..., im
 must be distinct). Let k=min(300,m)
. The jury will return the top k
 largest number(s) in [pi1,pi2,...,pim]
 in increasing order.
"4 m i1 i2 … im
" (1≤m≤n
, i1, i2, …, im
 must be distinct). Let k=min(300,m)
. The jury will return the top k
 largest number(s) in [posi1,posi2,…,posim]
 in increasing order.
Let ci
 be the usage count of queries of type i
 (1≤i≤4)
. Your query count must satisfy the following constraints:

c1+c2+c3+c4≤30.
c3+c4≤1.
Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤40
). The description of the test cases follows.

Interaction
The first line of each test case contains one integer n
 (2≤n≤890
). At this moment, the permutation p
 is chosen. The interactor in this task is not adaptive. In other words, the permutation p
 is fixed in every test case and does not change during the interaction.

To ask a query of type 1
, you need to print the line of the following form (without quotes):

"1 m i1 i2 … im
" (1≤m≤n
, i1,i2,…,im
 must be distinct)
After that, you receive k=min(60,m)
 integer(s) — the top k
 largest number(s) in [pi1,pi2,…,pim]
 in increasing order.

To ask a query of type 2
, you need to print the line of the following form (without quotes):

"2 m i1 i2 … im
" (1≤m≤n
, i1,i2,…,im
 must be distinct)
After that, you receive k=min(60,m)
 integer(s) — the top k
 largest number(s) in [posi1,posi2,…,posim]
 in increasing order.

To ask a query of type 3
, you need to print the line of the following form (without quotes):

"3 m i1 i2 … im
" (1≤m≤n
, i1,i2,…,im
 must be distinct)
After that, you receive k=min(300,m)
 integer(s) — the top k
 largest number(s) in [pi1,pi2,…,pim]
 in increasing order.

To ask a query of type 4
, you need to print the line of the following form (without quotes):

"4 m i1 i2 … im
" (1≤m≤n
, i1,i2,…,im
 must be distinct)
After that, you receive k=min(300,m)
 integer(s) — the top k
 largest number(s) in [posi1,posi2,…,posim]
 in increasing order.

Next, if your program has found the permutation p
, print the line of the following form (without quotes):

"! p1 p2 … pn
"
Note that this line is not considered a query and is not taken into account when counting the number of queries asked.

After this, proceed to the next test case.

After printing a query or the answer for a test case, do not forget to output the end of the line and flush the output. Otherwise, you will get the verdict Idleness Limit Exceeded. To do this, use:

fflush(stdout) or cout.flush() in C++;
System.out.flush() in Java;
flush(output) in Pascal;
stdout.flush() in Python;
see the documentation for other languages.
Hacks

To hack, follow the test format below.

The first line contains the number of test cases t
 (1≤t≤40
). The description of the test cases follows.

The first line of each test case contains one integer n
 (2≤n≤890
).

The second line of each test case contains n
 integers p1,p2,…,pn
, which is a permutation of {1,2,…,n}
.

Example
InputCopy
2
3

2 3

3

2

2



OutputCopy


3 2 3 1

2 1 2

! 3 1 2

4 1 1

! 2 1

Note
In the first test case, the hidden permutation is p=[3,1,2]
. Thus, pos=[2,3,1]
.

For the query "3 2 3 1", the jury returns 2
 and 3
 because 2
 and 3
 are the top k
 largest number(s) in [p3,p1]
, where k=min(300,m)=min(300,2)=2
.

For the query "2 1 2", the jury returns 3
 because 3
 is the top k
 largest number in [pos2]
, where k=min(60,m)=min(60,1)=1
.

Note that the example is only for understanding the statement and does not guarantee finding the unique permutation p
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
const int N=1010;
int T,n;
vector<int> Sv[N],Sp[N],prv[N],prp[N];

void init()
{
    srand(time(0));
    cin>>n;
    for(int i=1;i<N;i++)
        Sv[i].clear(),Sp[i].clear(),prv[i].clear(),prp[i].clear();
}

vector<int> ask(int ty,vector<int> &v)
{
    cout<<ty<<" "<<v.size();
    for(int i=0;i<v.size();i++)
        cout<<" "<<v[i];
    cout<<"\n"<<flush;
    int k;
    if(ty<3) k=min(60,(int)v.size());
    else k=min(300,(int)v.size());
    vector<int> res;
    for(int i=1;i<=k;i++)
    {
        int t;
        cin>>t;
        res.push_back(t);
    }
    return res;
}

void solve()
{
    int cnt=0,cntr=871,cntpr=30;
    vector<int> p(n+4);
    for(int i=1;i<=29;i++)
    {
        cnt++;
        Sv[cnt].push_back(i);
        cntr--;
        Sv[cntr].push_back(i);
    }
    for(int i=1;i<=29;i++)
    {
        for(int j=i+1;j<=29;j++)
        {
            cnt++;
            Sv[cnt].push_back(i),Sv[cnt].push_back(j);
            cntr--;
            Sv[cntr].push_back(i),Sv[cntr].push_back(j);
        }
    }
    for(int i=871,hd=1;i<890;i++,hd+=3)
    {
        int x=hd,y=hd+1,z=hd+2;
        if(x>29) x-=29;
        if(y>29) y-=29;
        if(z>29) z-=29;
        Sv[i].push_back(x),Sv[i].push_back(y),Sv[i].push_back(z);
    }
    for(int i=1;i<=29;i++)
    {
        vector<int> v,t;
        for(int j=1;j<=n;j++)
            if(find(Sv[j].begin(),Sv[j].end(),i)!=Sv[j].end())
                v.push_back(j);
        if(v.empty()) continue;
        t=ask(2,v);
        for(int j=0;j<t.size();j++)
            Sp[t[j]].push_back(i);
    }
    for(int i=1;i<=n;i++)
         sort(Sp[i].begin(),Sp[i].end()), sort(Sv[i].begin(),Sv[i].end());
    for(int i=1;i<=n;i++)
    {
        for(int j=871;j<=n;j++)
            if(Sp[i]==Sv[j]) p[i]=j;
    }
    for(int i=1;i<=n;i++)
    {
        if(Sp[i].size()==1) prp[Sp[i][0]].push_back(i);
        else if(Sp[i].size()==2) prp[30*Sp[i][0]+Sp[i][1]].push_back(i);    //hash the set
        //|S|>2 and empty set are ignored
    }
    for(int i=1;i<=n;i++)
    {
        if(Sv[i].size()==1) prv[Sv[i][0]].push_back(i);
        else if(Sv[i].size()==2) prv[30*Sv[i][0]+Sv[i][1]].push_back(i);    //hash the set
    }
    //necessary shuffle
    for(int i=1;i<N;i++)
    {
        if(prp[i].size()<2) continue;
        if(rand()&1) swap(prp[i][0],prp[i][1]);
    }
    for(int i=1;i<=1;i++)
    {
        vector<int> v,t;
        for(int j=1;j<N;j++)
        {
            if(prp[j].empty()) continue;
            else if(prp[j].size()==1)
            {
                p[prp[j][0]]=prv[j][0];
                prp[j].clear();
                prv[j].clear();
                continue;
            }
            v.push_back(prp[j][0]);
        }
        if(v.empty()) continue;
        t=ask(3,v);
        for(int j=1;j<N;j++)
        {
            if(prp[j].empty()) continue;
            if(t.empty()) break;
            if(prv[j][1]==t.back())
            {
                t.pop_back();
                p[prp[j][0]]=prv[j][1];
                p[prp[j][1]]=prv[j][0];
            }
            else
            {
                p[prp[j][0]]=prv[j][0];
                p[prp[j][1]]=prv[j][1];
            }
            prp[j].clear();
            prv[j].clear();
        }
    }
    cout<<"! ";
    for(int i=1;i<=n;i++)
        cout<<p[i]<<(i==n?'\n':' ');
    cout<<flush;
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
