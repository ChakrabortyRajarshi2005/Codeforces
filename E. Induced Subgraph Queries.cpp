E. Induced Subgraph Queries
time limit per test5 seconds
memory limit per test512 megabytes
You are given an unweighted, undirected graph G
 with n
 nodes and m
 edges. The graph G
 contains no self-loops or multiple edges.

We denote the node set of G
 as V
. For any node subset V′⊆V
, the corresponding induced subgraph, denoted by G[V′]
, is defined as follows:

G[V′]
 is the graph whose node set is V′
, and whose edge set consists of all edges in G
 with both endpoints in V′
.
Your task is to answer q
 queries. Each query provides three integers l
, r
, and k
. Denoting V′={l,l+1,…,r}
, you need to find the k
-th smallest value among f(l,G[V′])
, f(l+1,G[V′])
, …
 , f(r,G[V′])
 (i.e., the k
-th value in increasing order; repeated values are counted multiple times).

Here, f(u,G[V′])=⨁(u,v)∈G[V′]v
. In other words, it is the bitwise XOR value of the labels of all adjacent nodes of node u
 in graph G[V′]
.

You might want to read the notes for a better understanding.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤1.5⋅104
). The description of the test cases follows.

Each test case begins with two integers n
 and m
 (2≤n≤1.5⋅105
, 1≤m≤1.5⋅105
) — the number of nodes and edges, respectively.

The next m
 lines each contain two integers ui
 and vi
 (1≤ui,vi≤n
, ui≠vi
), representing an undirected edge between nodes ui
 and vi
.

The next line contains a single integer q
 (1≤q≤1.5⋅105
) — the number of queries.

Each of the next q
 lines contains three integers l
, r
, and k
 (1≤l≤r≤n
, 1≤k≤r−l+1
), defining a query about the induced subgraph G[{l,…,r}]
.

It is guaranteed that the graph contains no self-loops or multiple edges.

It is guaranteed that the sum of n
,m
, and q
 over all test cases does not exceed 1.5⋅105
, respectively.

Output
For each test case, output q
 integers, representing the answer for each query.

Example
InputCopy
2
4 5
1 3
1 4
2 3
2 4
3 4
3
1 2 2
1 3 1
2 4 3
2 1
2 1
3
1 1 1
2 2 1
1 2 2
OutputCopy
0
3
7
0
0
2
Note
In the first test case, the input graph G
 is the one in the following picture.

The given graph G
.
In the first query, the induced subgraph G[{1,2}]
 is the one in the following picture. We can see that nodes 1
 and 2
 have no adjacent nodes. Thus, f(1,G[{1,2}])=f(2,G[{1,2}])=0
. The 2
-nd smallest value is 0
.

G[{1,2}]
.
In the second query, the induced subgraph G[{1,2,3}]
 is the one in the following picture. We can see that f(1,G[{1,2,3}])=3
, f(2,G[{1,2,3}])=3
, and f(3,G[{1,2,3}])=1⊕2=3
. The 1
-st smallest value is 3
.

G[{1,2,3}]
.
In the third query, the induced subgraph G[{2,3,4}]
 is the one in the following picture. We can see that f(2,G[{2,3,4}])=3⊕4=7
, f(3,G[{2,3,4}])=2⊕4=6
, and f(4,G[{2,3,4}])=2⊕3=1
. The 3
-rd smallest value is 7
.

G[{2,3,4}]
.



#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(),a.end()
#define pb push_back
#define sz(a) ((int)a.size())

using ll=long long;
using u32=unsigned int;
using u64=unsigned long long;
using i128=__int128;
using u128=unsigned __int128;
using f128=__float128;

using pii=pair<int,int>;
using pll=pair<ll,ll>;

template<typename T> using vc=vector<T>;
template<typename T> using vvc=vc<vc<T>>;
template<typename T> using vvvc=vc<vvc<T>>;

using vi=vc<int>;
using vll=vc<ll>;
using vvi=vc<vi>;
using vvll=vc<vll>;

#define vv(type,name,n,...) \
    vector<vector<type>> name(n,vector<type>(__VA_ARGS__))
#define vvv(type,name,n,m,...) \
    vector<vector<vector<type>>> name(n,vector<vector<type>>(m,vector<type>(__VA_ARGS__)))

template<typename T> using min_heap=priority_queue<T,vector<T>,greater<T>>;
template<typename T> using max_heap=priority_queue<T>;

// https://trap.jp/post/1224/
#define rep1(n) for(ll i=0; i<(ll)(n); ++i)
#define rep2(i,n) for(ll i=0; i<(ll)(n); ++i)
#define rep3(i,a,b) for(ll i=(ll)(a); i<(ll)(b); ++i)
#define rep4(i,a,b,c) for(ll i=(ll)(a); i<(ll)(b); i+=(c))
#define cut4(a,b,c,d,e,...) e
#define rep(...) cut4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define per1(n) for(ll i=((ll)n)-1; i>=0; --i)
#define per2(i,n) for(ll i=((ll)n)-1; i>=0; --i)
#define per3(i,a,b) for(ll i=((ll)a)-1; i>=(ll)(b); --i)
#define per4(i,a,b,c) for(ll i=((ll)a)-1; i>=(ll)(b); i-=(c))
#define per(...) cut4(__VA_ARGS__,per4,per3,per2,per1)(__VA_ARGS__)
#define rep_subset(i,s) for(ll i=(s); i>=0; i=(i==0?-1:(i-1)&(s)))

template<typename T, typename S> constexpr T ifloor(const T a, const S b){return a/b-(a%b&&(a^b)<0);}
template<typename T, typename S> constexpr T iceil(const T a, const S b){return ifloor(a+b-1,b);}

template<typename T>
void sort_unique(vector<T> &vec){
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
}

template<typename T, typename S> constexpr bool chmin(T &a, const S b){if(a>b) return a=b,true; return false;}
template<typename T, typename S> constexpr bool chmax(T &a, const S b){if(a<b) return a=b,true; return false;}

template<typename T, typename S> istream& operator >> (istream& i, pair<T,S> &p){return i >> p.first >> p.second;}
template<typename T, typename S> ostream& operator << (ostream& o, const pair<T,S> &p){return o << p.first << ' ' << p.second;}

#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(vector<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(unordered_set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif

template<typename T> void print(vector<T> x){for(auto i: x) cout << i << ' ';cout << "\n";}
template<typename T> void print(set<T> x){for(auto i: x) cout << i << ' ';cout << "\n";}
template<typename T> void print(unordered_set<T> x){for(auto i: x) cout << i << ' ';cout << "\n";}
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

template<typename T> istream& operator >> (istream& i, vector<T> &vec){for(auto &x: vec) i >> x; return i;}

vvi read_graph(int n, int m, int base=1){
    vvi adj(n);
    for(int i=0,u,v; i<m; ++i){
        cin >> u >> v,u-=base,v-=base;
        adj[u].pb(v),adj[v].pb(u);
    }
    return adj;
}

vvi read_tree(int n, int base=1){return read_graph(n,n-1,base);}

template<typename T, typename S> pair<T,S> operator + (const pair<T,S> &a, const pair<T,S> &b){return {a.first+b.first,a.second+b.second};}

template<typename T> constexpr T inf=0;
template<> constexpr int inf<int> = 0x3f3f3f3f;
template<> constexpr ll inf<ll> = 0x3f3f3f3f3f3f3f3f;

template<typename T> vector<T> operator += (vector<T> &a, int val){for(auto &i: a) i+=val; return a;}

template<typename T> T isqrt(const T &x){T y=sqrt(x+2); while(y*y>x) y--; return y;}

#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())

//#include<atcoder/all>
//using namespace atcoder;

//using mint=modint998244353;
//using mint=modint1000000007;

const int N=1<<18,K=1<<10;

struct DS{
    int big[N/K],small[N];
    void ins(int x){
        small[x]++;
        big[x>>10]++;
    }
    void del(int x){
        small[x]--;
        big[x>>10]--;
    }
    int kth(int k){
        k--;
        int cur=0;
        while(big[cur]<=k) k-=big[cur++];
        cur<<=10;
        while(small[cur]<=k) k-=small[cur++];
        return cur;
    }
}ds;

void ahcorz(){
    int n,m; cin >> n >> m;
    vvi adj=read_graph(n,m);
    vi block(n);
    int cur=0;
    rep(n){
        if(cur>=n) break;
        int tot=0;
        while(cur<n&&tot<K){
            tot+=sz(adj[cur])+1;
            block[cur++]=i;
        }
    }
    int q; cin >> q;
    vc<array<int,4>> qq(q);
    vi res(q);
    rep(q){
        int l,r,k; cin >> l >> r >> k; l--,r--;
        qq[i]={l,r,k,i};
    }
    sort(all(qq),[&](array<int,4> arr1, array<int,4> arr2){
        if(block[arr1[0]]!=block[arr2[0]]) return block[arr1[0]]<block[arr2[0]];
        if(block[arr1[0]]&1) return arr1[1]>arr2[1];
        else return arr1[1]<arr2[1];
    });
    vi val(n);
    int l=0,r=0;
    ds.ins(0);
    auto ins=[&](int i){
        for(auto j: adj[i]){
            if(j>=l&&j<=r){
                ds.del(val[j]);
                val[j]^=i+1,val[i]^=j+1;
                ds.ins(val[j]);
            }
        }
        ds.ins(val[i]);
    };
    auto del=[&](int i){
        ds.del(val[i]);
        for(auto j: adj[i]){
            if(j>=l&&j<=r){
                ds.del(val[j]);
                val[j]^=i+1,val[i]^=j+1;
                ds.ins(val[j]);
            }
        }
    };
    auto gogo=[&](int l2, int r2){
        while(l>l2){
            ins(l-1);
            l--;
        }
        while(r<r2){
            ins(r+1);
            r++;
        }
        while(l<l2){
            l++;
            del(l-1);
        }
        while(r>r2){
            r--;
            del(r+1);
        }
    };
    for(auto [l2,r2,k,i]: qq){
        gogo(l2,r2);
        res[i]=ds.kth(k);
    }
    rep(i,l,r+1) ds.del(val[i]);
    rep(q) print(res[i]);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout << fixed << setprecision(20);
    int t=1;
    cin >> t;
    while(t--) ahcorz();
}
