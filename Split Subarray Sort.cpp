Split Subarray Sort
You have a parameter 
K
K.

Consider performing the following action on an array 
A
A of length 
N
N exactly once:

Choose an integer 
M
M and then 
M
M intervals 
[
L
1
,
R
1
]
,
[
L
2
,
R
2
]
,
…
,
[
L
M
,
R
M
]
[L 
1
​
 ,R 
1
​
 ],[L 
2
​
 ,R 
2
​
 ],…,[L 
M
​
 ,R 
M
​
 ] such that:
1
≤
L
i
≤
R
i
≤
N
1≤L 
i
​
 ≤R 
i
​
 ≤N
L
1
=
1
L 
1
​
 =1 and 
R
M
=
N
R 
M
​
 =N
L
i
=
R
i
−
1
+
1
L 
i
​
 =R 
i−1
​
 +1 for all 
2
≤
i
≤
M
2≤i≤M
R
i
−
L
i
+
1
≤
K
R 
i
​
 −L 
i
​
 +1≤K
For each 
i
=
1
…
M
i=1…M, sort 
A
[
L
i
,
R
i
]
A[L 
i
​
 ,R 
i
​
 ] (i.e. replace the subarray with the sorted version of it) where 
A
[
L
,
R
]
A[L,R] denotes the subarray 
[
A
L
,
A
L
+
1
,
…
,
A
R
]
[A 
L
​
 ,A 
L+1
​
 ,…,A 
R
​
 ].
Less formally, you divide the array into several subarrays, each of length at most 
K
K, and then sort each part and concatenate the pieces back together.

Define 
f
(
A
)
f(A) as the lexicographically minimum array possible at the end of the above process.

You are given an array 
A
A of length 
N
N. It is guaranteed that 
A
A is a permutation of integers in 
[
1
,
N
]
[1,N].

Solve 
Q
Q queries of the following type:

You are given 
3
3 integers, 
L
L, 
R
R and 
X
X.
Let 
B
=
A
[
L
,
R
]
B=A[L,R] and 
C
=
f
(
B
)
C=f(B). Find the 
X
X-th element in 
C
C, i.e. 
C
X
C 
X
​
 .
Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains 
3
3 integers - 
N
,
K
N,K and 
Q
Q.
The second line contains 
N
N integers - 
A
1
,
A
2
,
…
,
A
N
A 
1
​
 ,A 
2
​
 ,…,A 
N
​
 .
The next 
Q
Q lines each contain 
3
3 integers each - 
L
,
R
L,R and 
X
X representing a query.
Output Format
For each test case, output 
Q
Q integers on the same line - the answers to the queries in the same order.

Constraints
1
≤
T
≤
10
4
1≤T≤10 
4
 
2
≤
N
≤
2
⋅
10
5
2≤N≤2⋅10 
5
 
1
≤
K
≤
N
1≤K≤N
1
≤
Q
≤
2
⋅
10
5
1≤Q≤2⋅10 
5
 
1
≤
A
i
≤
N
1≤A 
i
​
 ≤N
A
i
≠
A
j
A 
i
​
 =A 
j
​
  for all 
1
≤
i
<
j
≤
N
1≤i<j≤N
1
≤
L
≤
R
≤
N
1≤L≤R≤N
1
≤
X
≤
(
R
−
L
+
1
)
1≤X≤(R−L+1)
The sum of 
N
N and the sum of 
Q
Q both do not exceed 
2
⋅
10
5
2⋅10 
5
 .
Sample 1:
Input
Output
3
4 2 5
2 1 4 3
1 4 1
1 4 2
1 4 3
1 4 4
3 4 1
6 3 11
2 6 5 1 4 3
1 6 1
1 6 2
1 6 3
1 6 4
1 6 5
1 6 6
2 3 2
2 5 1
5 5 1
2 5 3
3 6 4
2 1 2
2 1
1 2 1
1 2 2
1 2 3 4 3
2 1 5 6 3 4 6 1 4 6 3
2 1
Explanation:
Test Case 1 : Split 
A
=
[
2
,
1
,
4
,
3
]
A=[2,1,4,3] as 
[
2
,
1
]
+
[
4
,
3
]
[2,1]+[4,3] and sort to get 
f
(
A
)
=
[
1
,
2
,
3
,
4
]
f(A)=[1,2,3,4].

Test Case 2 : Split 
A
=
[
2
,
6
,
5
,
1
,
4
,
3
]
A=[2,6,5,1,4,3] as 
[
2
]
+
[
6
,
5
,
1
]
+
[
4
,
3
]
[2]+[6,5,1]+[4,3] and sort to get 
f
(
A
)
=
[
2
,
1
,
5
,
6
,
3
,
4
]
f(A)=[2,1,5,6,3,4].
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std ;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define ll long long 
#define ull unsigned long long
#define lld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vi vector<int>
#define nline "\n"
#define inf (ll)1e18
#define iinf (int)2e9
#define eb emplace_back
#define vb vector<bool>
#define vll vector<ll> 
#define vvll vector<vll>
#define vpll vector<pll>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define nline "\n"
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fs first
#define sc second
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
 
#define print(k) {for(auto v : k){cout << v << " ";} cout << endl;}

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;

int rand(int l, int r){
     static mt19937 
     rng(chrono::steady_clock::now().time_since_epoch().count());
     uniform_int_distribution<int> ludo(l, r); 
     return ludo(rng);
}


ll mod = 998244353;
int sz = 1000005;
ll fact[1000005];
ll ifact[1000005];
 
ll power(ll x, ll n) {
    if(n==0) return 1;
    x = x%mod;
    if(x==0) return 0; 
    ll pow = 1;
    while (n) {
        if (n & 1) pow = (pow*x)%mod;
        n = n >> 1;
        x = (x*x)%mod;
    }
    return pow;
}
 
ll inv_mod(ll x) { return power(x , mod - 2)%mod; }
 
void factorial() {
    fact[0] = fact[1] = 1;
    ifact[0] = ifact[1] = 1;
    for(int i = 2 ; i < sz ; i ++)
        fact[i] = (fact[i-1]*i)%mod;    
    ifact[sz-1] = inv_mod(fact[sz-1]);
    for(int i = sz-2 ; i > 0 ; i --)
        ifact[i] = (ifact[i+1]*(i+1))%mod;
}
 
ll ncr(ll n , ll r) {
    if(n<r || r<0) return 0;
    if(r == 0) return 1;
    return (((fact[n]*ifact[n-r])%mod)*ifact[r])%mod;
}


ll n , k , q;

struct Info {
  ll mn = 1e9;
  ll mx = -1e9;
  ll sz = 0;
};
 
Info operator+(const Info &l, const Info &r) {
    Info newnode;
    newnode.mx = max(l.mx , r.mx);
    newnode.mn = min(l.mn , r.mn);
    newnode.sz = l.sz + r.sz;
    return newnode;
}


template<class Info>
struct SegmentTree {
  int n;
  vector<Info> info;
  SegmentTree() : n(0) {}
  SegmentTree(int n_, Info v_ = Info()) {
    init(n_, v_);
  }
  template<class T>
  SegmentTree(vector<T> init_) {
    init(init_);
  }
  void init(int n_, Info v_ = Info()) {
    init(vector<Info>(n_, v_));
  }
  template<class T>
  void init(vector<T> init_) {
    n = init_.size();
    info.assign(4 << __lg(n), Info());
    function<void(int, int, int)> build = [&](int p, int l, int r) {
      if (r - l == 1) {
        info[p] = init_[l];
        return;
      }
      int m = (l + r) / 2;
      build(2 * p, l, m);
      build(2 * p + 1, m, r);
      pull(p);
    };
    build(1, 0, n);
  }
  void pull(int p) {
    info[p] = info[2 * p] + info[2 * p + 1];
  }
  void modify(int p, int l, int r, int x, const Info &v) {
    if (r - l == 1) {
      info[p] = v;
      return;
    }
    int m = (l + r) / 2;
    if (x < m) modify(2 * p, l, m, x, v);
    else modify(2 * p + 1, m, r, x, v);
    pull(p);
  }
  void modify(int p, const Info &v) {
    modify(1, 0, n, p, v);
  }
  Info rangeQuery(int p, int l, int r, int x, int y) {
    if (l >= y || r <= x) return Info();
    if (l >= x && r <= y) return info[p];
    int m = (l + r) / 2;
    return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
  }
  Info rangeQuery(int l, int r) {
    return rangeQuery(1, 0, n, l, r);
  }
  template<class F>
  int findFirst(int p, int l, int r, int x, int y, F pred) {
    if (l >= y || r <= x || !pred(info[p])) return -1;
    if (r - l == 1) return l;
    
    int m = (l + r) / 2;
    int res = findFirst(2 * p, l, m, x, y, pred);
    if (res == -1) {
      res = findFirst(2 * p + 1, m, r, x, y, pred);
    }
    return res;
  }
  template<class F>
  int findFirst(int l, int r, F pred) {
    return findFirst(1, 0, n, l, r, pred);
  }
};



#define maxsz 200005
#define logmax 18

ll parent[maxsz];
ll memo[maxsz][logmax];

void preprocess(ll n)
{
    for(ll i = 0 ; i < logmax ; i ++)
    {
        for(ll j = 0 ; j <= n ; j ++)
        {
            if(i == 0) 
            {
                memo[j][i] = parent[j];
            }
            else{
                memo[j][i] = memo[memo[j][i-1]][i-1];
            }
        }
    }
}




ll f(ll x , ll y) {
    return (x + y);
}

struct node {
    node *l, *r;
    ll val = 0;

    node(ll val) : l(nullptr), r(nullptr), val(val) {}
    node(node *l, node *r) : l(l), r(r), val(0ll) {
        if (l) val = f(val , l->val);
        if (r) val = f(val , r->val);
    }
};

node* build(ll a[], ll lx, ll rx) {
    if (rx - lx == 1)
    {
        return new node(a[lx]);
    }
    ll m = (lx + rx) / 2;
    return new node(build(a, lx, m), build(a, m, rx));
}

ll range_calc(node* v, ll lx, ll rx, ll l, ll r) {
    if (r <= lx || rx <= l)
        return 0ll;
    if (l <= lx && rx <= r)
    {
        return v->val;
    }
    ll m = (lx + rx) / 2;
    return f(range_calc(v->l, lx, m, l, r) , range_calc(v->r, m, rx, l, r));
}

node* update(node* v, ll lx, ll rx, ll pos, ll new_val) {
    if (rx - lx == 1)
        return new node(new_val);
    ll m = (lx + rx) / 2;
    if (pos < m)
        return new node(update(v->l, lx, m, pos, new_val), v->r);
    else
        return new node(v->l, update(v->r, m, rx, pos, new_val));
}


void solve()
{
    cin >> n >> k >> q;

    SegmentTree<Info> god;
    god.init(n+1);

    ll a[n+1] = {0};
    
    node *head = build(a , 0 , n);
    vector<node*> versions;
    versions.pb(head);

    ll ocr[n+1] = {0};

    for(int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];
        ocr[a[i]] = i;
        god.modify(i,  {a[i] , a[i] , 1});
    }


    for(int i = 1 ; i <= n ; i ++)
    {
        head = update(head , 0 , n , ocr[i] , 1);
        versions.pb(head);
    }

    vpll intv;
    vll st[n+1];
    vll ed[n+1];

    {
        set<pll> intv;
        intv.insert({n+n+1 , inf});
        intv.insert({0, n+n});
        intv.insert({-inf, -1});
        for(int i = 1 ; i <= n ; i ++)
        {
            int p = ocr[i];
            // break
            {
                pll src=  {p , inf};
                auto it = intv.lower_bound(src);
                it = prev(it);

                int lx = (*it).first;
                int rx = (*it).second;

                intv.erase({lx,rx});
                if(lx <= p-1)
                {
                    intv.insert({lx , p-1});
                }

                if(p+1 <= rx)
                {
                    intv.insert({p+1 , rx});
                }

                {
                    ll lxx = p;
                    ll rxx = -inf;

                    src = {lxx , rxx};
                    auto it1 = intv.lower_bound(src);

                    if((*it1).second != inf)
                    {
                        lxx = (*it1).first;
                        rxx = (*it1).second;
                        it1 = prev(it1);
                        
                        ll lxxx = max((*it1).second + 1 , lxx - (k-1));
                        ll rxxx = min(rxx - (k-1) , lxx - 1);

                        if(lxxx <= rxxx)
                        {
                        //    cout << lxxx << " " << rxxx << " = " << lxx << " " << i << endl;
                            st[lxxx].pb(lxx);
                            ed[rxxx].pb(lxx);
                        }
                    }
                }
            }
        }
    }


    {
        multiset<ll> ms;
        for(int i = 0 ; i < n ; i ++)
        {
            for(ll x : st[i])
            {
                ms.insert(x);
            }


            if(ms.size() == 0)
            {
                parent[i] = min(n , i + k);
            }
            else
            {
                parent[i] = *ms.begin();
            }

            for(ll x : ed[i])
            {
                ms.erase(ms.find(x));
            }
        }
    }


    parent[n] = n;

    preprocess(n);


    while(q--)
    {
        ll lx , rx , x;
        cin >> lx >> rx >> x;
        lx--;
        rx--;
        x--;
        x += lx;

        for(int p = logmax - 1 ; p >= 0 ; p --)
        {
            if(memo[lx][p]  <= x)
            {
                lx = memo[lx][p];
            }
        }
        
        while(parent[lx]  <= x )
        {
            lx = parent[lx];
        }

        x -= lx;

        rx = min(rx , parent[lx] - 1);

        ll lxx = lx;
        ll rxx = rx;

        //cout << x << " " << lx << " " << rx << endl;

         assert(x < rxx - lxx + 1);


        
        {
            int low = 1 , high = n;
            while(low < high)
            {
                int mid = (low + high)/2;
                ll cnt = range_calc(versions[mid] , 0 , n , lxx , rxx+1);
                if(cnt < x+1)
                {
                    low = mid+1;
                }
                else
                {
                    high = mid;
                }
            }

            cout << low << " ";
        }
    }

    cout << endl;

}
signed main(){
    
    fastio();


    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
    
    int t=1;
    cin >> t;

    factorial();

    for(int i = 1 ; i <= t ; i ++) {
        solve();
    }    
    return 0;
}








