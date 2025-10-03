F. To the Infinity
time limit per test2 seconds
memory limit per test1024 megabytes

You are given a full binary tree∗
 of n
 nodes, rooted at node 1
. For each node u
 (1≤u≤n
), we define function fu:R+→R+
 as follows:

If u
 is a leaf†
, then fu(x)=x
;
Otherwise, denote the left child of u
 as lu
 and the right child of u
 as ru
, then fu(x)=(flu(x))fru(x)
.
For two nodes u
 and v
, we say u≺v
 if and only if one of the following holds:

fu(x)<fv(x)
 when x→∞
;
u<v
, and fu(x)=fv(x)
 when x→∞
‡
.
It can be shown that for any two distinct nodes u
 and v
, either u≺v
 or v≺u
 holds.

You have to sort the nodes by order ≺
. Formally, you need to find a permutation§
 p
 of length n
, such that for every 1≤i<n
, pi≺pi+1
.

∗
A full binary tree is a rooted tree, in which each node has 0
 or 2
 children.

†
A leaf is any vertex without children.

‡
Here, fu(x)<fv(x)
 when x→∞
 is equivalent to the following description: there exists a positive number N
 such that for all x>N
, fu(x)<fv(x)
 holds. The same is defined for fu(x)=fv(x)
 when x→∞
.

§
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

The first line of each test case contains a single integer n
 (1≤n≤4⋅105
, n
 is odd) — the size of the full binary tree.

Then n
 lines follow, the i
-th line containing two integers li
 and ri
 (0≤li,ri≤n
) — the left child and the right child of node i
. If i
 is a leaf, then li=ri=0
. It is guaranteed that the given input forms a full binary tree rooted at node 1
.

It is guaranteed that the sum of n
 over all test cases does not exceed 4⋅105
.

Output
For each test case, output n
 integers p1,p2,…,pn
 (1≤pi≤n
, all pi
 are distinct) — the permutation you found. You need to guarantee that for each 1≤i<n
, pi≺pi+1
.

Example
InputCopy
4
3
2 3
0 0
0 0
5
2 3
4 5
0 0
0 0
0 0
9
2 3
4 5
0 0
0 0
6 7
8 9
0 0
0 0
0 0
1
0 0
OutputCopy
2 3 1 
3 4 5 2 1 
3 4 7 8 9 6 5 2 1 
1 
Note
In the first test case, f2(x)=f3(x)=x
, and f1(x)=(f2(x))f3(x)=xx
. When x→∞
, it is clear that f2(x)=f3(x)<f1(x)
. Thus, 2≺3≺1
.

In the second test case, f3(x)=f4(x)=f5(x)=x
, f2(x)=(f4(x))f5(x)=xx
, and f1(x)=(f2(x))f3(x)=xx2
. It is clear that x<x2
 when x→∞
, so f2(x)<f1(x)
. Similarly, f3(x)=f4(x)=f5(x)<f2(x)<f1(x)
. Thus, 3≺4≺5≺2≺1
.


#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long ull;
 
const int MAXN = 4e5 + 10;
 
ull A = mt19937_64(time(0))();
 
inline ull shift(ull x) {
	return x ^= A, x ^= x << 13, x ^= x >> 7, x ^= x << 11, x ^= A;
}
 
struct node {
	int l, r, num; ull val;
} t[MAXN * 20]; int cnt, rt[MAXN];
 
void add(int &p, int pre, int l, int r, int k, ull x) {
	t[p = ++cnt] = t[pre], t[p].val += x, t[p].num++;
	if (l == r) return ; int mid = l + r >> 1;
	if (k <= mid) add(t[p].l, t[pre].l, l, mid, k, x);
	else add(t[p].r, t[pre].r, mid + 1, r, k, x);
}
 
bool find(int p, int pre, int l, int r) {
	if (l == r) return t[p].num > t[pre].num; int mid = l + r >> 1;
	if (t[t[p].r].val == t[t[pre].r].val) return find(t[p].l, t[pre].l, l, mid);
	else return find(t[p].r, t[pre].r, mid + 1, r);
}
 
int n, l[MAXN], r[MAXN], fa[MAXN], d[MAXN];
 
int rk[MAXN], tot, lst; ull h[MAXN];
 
struct cmp {
	bool operator () (int x, int y) {
		return h[x] == h[y] ? x > y : find(rt[x], rt[y], 1, n);
	}
}; priority_queue<int, vector<int>, cmp> q;
 
 
inline 
void upd(int u) {
	h[u] = h[l[u]] + shift(h[r[u]]);
	add(rt[u], rt[l[u]], 1, n, rk[r[u]], shift(h[r[u]]));
}
 
int T;
 
int main() {
	for (scanf("%d", &T); T--; ) {
		scanf("%d", &n), cnt = lst = tot = 0;
		for (int i = 1; i <= n; i++) rt[i] = 0; 
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &l[i], &r[i]);
			d[i] = (l[i] && r[i] ? 2 : 0), fa[l[i]] = fa[r[i]] = i;
		}
		for (int i = 1; i <= n; i++) if (!d[i]) h[i] = 1, q.emplace(i);
		for (int u; !q.empty(); ) {
			printf("%d ", u = q.top()), q.pop();
			if (h[u] != h[lst]) tot++; lst = u, rk[u] = tot;
			if (!--d[fa[u]]) upd(fa[u]), q.push(fa[u]);
		}
		puts("");
	}
}
