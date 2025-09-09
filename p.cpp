
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
vector<int> Sv[N],Sp[N];

void init()
{
    cin>>n;
    for(int i=1;i<N;i++)
        Sv[i].clear(),Sp[i].clear();
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
    int cnt=0;
    vector<int> p(n+4);
    for(int i=1;i<=30;i++)
        Sv[++cnt].push_back(i);
    for(int i=1;i<=30;i++)
    {
        for(int j=i+1;j<=30;j++)
        {
            cnt++;
            Sv[cnt].push_back(i),Sv[cnt].push_back(j);
        }
    }
    for(int i=1;i<=9;i++)
    {
        int cur=1;
        while(1)
        {
            int nxt=cur+i;
            if(nxt>29) nxt-=29;
            cnt++;
            Sv[cnt].push_back(30);
            Sv[cnt].push_back(cur);
            Sv[cnt].push_back(nxt);
            cur=nxt;
            if(nxt==1) break;
        }
    }
    vector<int> vl(11),vm(11),vr(11);
    for(int i=1;i<=10;i++)
        vl[i]=i,vm[i]=10+i,vr[i]=20+i;
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=10;j++)
        {
            cnt++;
            Sv[cnt].push_back(vl[j]);
            Sv[cnt].push_back(vm[j]);
            Sv[cnt].push_back(vr[j]);
        }
        for(int j=0;j<10;j++)
            vr[j]=vr[j+1];
        vr[10]=vr[0];
    }
    for(int i=1,cur=1;i<=29;i++)
    {
        int x=cur,y=cur+1,z=cur+2;
        while(x>29) x-=29;
        while(y>29) y-=29;
        while(z>29) z-=29;
        cnt++;
        Sv[cnt].push_back(x);
        Sv[cnt].push_back(y);
        Sv[cnt].push_back(z);
        cur+=3;
    }
    for(int i=1;i<=30;i++)
    {
        vector<int> v,t;
        for(int j=1;j<=n;j++)
            if(find(Sv[j].begin(),Sv[j].end(),i)!=Sv[j].end())
                v.push_back(j);
        if(v.empty()) continue;
        if(i<30) t=ask(2,v);
        else t=ask(4,v);
        for(int j=0;j<t.size();j++)
            Sp[t[j]].push_back(i);
    }
    for(int i=1;i<=n;i++)
         sort(Sp[i].begin(),Sp[i].end()), sort(Sv[i].begin(),Sv[i].end());
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if((!Sp[i].empty())&&Sp[i]==Sv[j]) p[i]=j;
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
