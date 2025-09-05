E2. Beyond the Palindrome (Hard Version)
time limit per test3 seconds
memory limit per test1024 megabytes

This is the hard version of the problem. The difference between the versions is that in this version, n≤2⋅107
, and the sum of n
 over all test cases does not exceed 108
. You can hack only if you solved all versions of this problem.

For a binary string∗
 r
, we define f(r)
 as the result of the following process:

Delete all 10
 substrings†
 simultaneously from r
;
Repeat the above operation until there are no 10
 substrings in r
.
For example, f(100110001)=001
 because r
 changes as follows: 10–––0110–––001→010–––01→001
.

We call a binary string s
 almost-palindrome if and only if f(s)=f(rev(s))
‡
.

Aquawave has given you an integer n
. You have to help him find the number of distinct almost-palindrome binary strings of length n
, modulo 998244353
.

∗
A binary string is a string where each character is either 0
 or 1
.

†
A string a
 is a substring of a string b
 if a
 can be obtained from b
 by the deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

‡
rev(s)
 is the string obtained by writing s
 from right to left. For example, rev(10100)=00101
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The only line of each test case contains a single integer n
 (1≤n≤2⋅107
) — the length of the binary strings.

It is guaranteed that the sum of n
 over all test cases does not exceed 108
.

Output
For each test case, output a single integer — the number of distinct almost-palindrome binary strings of length n
, modulo 998244353
.

Example
InputCopy
12
1
2
3
4
5
6
7
8
9
10
100
1024
OutputCopy
2
2
4
8
12
26
44
86
164
302
307217648
950903700
Note
In the first test case, all binary strings of length 1
 are almost-palindrome.

In the second test case, all almost-palindrome binary strings of length 2
 are 00
 and 11
.

In the third test case, all almost-palindrome binary strings of length 3
 are 000
, 010
, 101
, and 111
.




#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int MAXN = 2e7 + 10;
const int mod = 998244353;
 
inline int add(int x, int y) { return x += y, x < mod ? x : x - mod; }
inline int sub(int x, int y) { return x -= y, x < 0 ? x + mod : x; }
inline void cadd(int &x, int y) { x += y, x < mod || (x -= mod); }
inline void csub(int &x, int y) { x -= y, x < 0 && (x += mod); }
 
inline 
int qpow(int b, int p) {
	int res = 1;
	for (; p; b = (ll)b * b % mod, p >>= 1) if (p & 1) res = (ll)res * b % mod;
	return res;
}
 
int f[MAXN], g[MAXN], p[MAXN], tot;
 
int fac[MAXN], ifac[MAXN];
 
inline 
void init(int n) {
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!f[i]) p[++tot] = i, f[i] = g[i] = i + (i > 2);
		for (int j = 1; j <= tot; j++) {
			if (i * p[j] > n) break;
			if (i % p[j] == 0) {
				g[i * p[j]] = g[i] * p[j] + (j > 1);
				f[i * p[j]] = f[i] / g[i] * g[i * p[j]];
				break;
			}
			f[i * p[j]] = f[i] * (p[j] + (j > 1));
			g[i * p[j]] = p[j] + (j > 1);
		}
	}
	*fac = 1;
	for (int i = 1; i <= n; i++) fac[i] = (ll)fac[i - 1] * i % mod;
	ifac[n] = qpow(fac[n], mod - 2);
	for (int i = n; i; i--) ifac[i - 1] = (ll)ifac[i] * i % mod;
}
 
int T, n, ans;
 
int main() {
	for (scanf("%d", &T), init(2e7 + 1); T--; ) {
		scanf("%d", &n), ans = 0;
		for (int i = 0; i <= n; i++) {
			ans = (ans + (ll)ifac[i] * ifac[n - i] % mod * sub(f[abs(n - i * 2 - 1)], f[abs(n - i * 2)])) % mod;
		}
		ans = (ll)ans * fac[n] % mod;
		cadd(ans, ans), (n & 1 ? cadd : csub)(ans, qpow(2, n));
		printf("%d\n", ans);
	}
}
