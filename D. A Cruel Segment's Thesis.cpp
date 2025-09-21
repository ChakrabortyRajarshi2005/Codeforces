D. A Cruel Segment's Thesis
time limit per test2 seconds
memory limit per test256 megabytes
You are given n
 segments on a number line. The i
-th segment is represented as [li,ri]
. Initially, all the segments are unmarked.

You perform the following operation repeatedly until there are no unmarked segments left:

In the k
-th operation, if there are at least two unmarked segments, choose any two unmarked segments [li,ri]
 and [lj,rj]
, mark both of them, and add a new marked segment [xk,yk]
 satisfying the following conditions:
li≤xk≤ri
,
lj≤yk≤rj
,
xk≤yk
.
If there is exactly one unmarked segment remaining, mark it.
Your task is to determine the maximum possible sum of lengths of all the marked segments at the end of the process. Note that the length of a segment ([l,r])
 is r−l
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (1≤n≤2⋅105
) — the number of segments.

Each of the next n
 lines contains two integers li
 and ri
 (1≤li≤ri≤109
) — the i
-th segment.

It is guaranteed that the sum of n
 across all test cases does not exceed 2⋅105
.

Output
For each test case, print a single integer — the maximum possible total length of all marked segments at the end of the process.

Example
InputCopy
4
2
1 1000000000
1 1000000000
3
1 10
2 15
3 9
5
1 11
2 7
15 20
1 3
11 15
1
1000000000 1000000000
OutputCopy
2999999997
42
59
0
Note
In the first test case, we choose the given two segments and make the new segment [1,109]
.

In the second test case, we choose the segments [1,10]
 and [2,15]
 and make the new segment [1,15]
. Now, [3,9]
 is the only segment that is left unmarked, and it will be marked in the next step.



Codeforces (c) 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

#define fo(i, a, b) for (ll i = a; i < b; i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<pl> a(n);
        fo(i, 0, n)cin >> a[i].first >> a[i].second;
        ll ans = 0;
        fo(i, 0, n)ans += a[i].second - a[i].first + 1;
        ans += n / 2;
        vector<pair<ll, pl>> b(n);
        fo(i, 0, n) {
            b[i].second = a[i];
            b[i].first = a[i].first + a[i].second;
        }
        sort(b.begin(), b.end());
        if (n % 2 == 0) {
            fo(i, 0, n) {
                ans += a[i].second;
            }
            fo(i, 0, n / 2) {
                ans -= b[i].first;
            }
            cout << ans - n - n / 2 << "\n";
        }
        else {
            ll k = 0, w = 0;
            fo(i, 0, n) {
                w += a[i].second;
            }
            fo(i, 0, n / 2+1) {
                w-= b[i].first;
            }
            fo(i, 0, n / 2 + 1) {
                k = max(k, w + b[i].S.F);
            }
            w += b[n / 2].first;
            fo(i, n / 2 + 1, n) {
                k = max(k, w - b[i].S.S);
            }
            cout << ans + k  - n - n / 2 << "\n";
        }
    }
}
