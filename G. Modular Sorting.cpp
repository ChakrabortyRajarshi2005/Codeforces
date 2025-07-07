G. Modular Sorting
time limit per test5 seconds
memory limit per test256 megabytes
You are given an integer m
 (2≤m≤5⋅105
) and an array a
 consisting of nonnegative integers smaller than m
.

Answer queries of the following form:

1
 i
 x
: assign ai:=x
2
 k
: in one operation, you may choose an element ai
 and assign ai:=(ai+k)(modm)
∗
 — determine if there exists some sequence of (possibly zero) operations to make a
 nondecreasing†
.
Note that instances of query 2
 are independent; that is, no actual operations are taking place. Instances of query 1
 are persistent.

∗
a(modm)
 is defined as the unique integer b
 such that 0≤b<m
 and a−b
 is an integer multiple of m
.

†
An array a
 of size n
 is called nondecreasing if and only if ai≤ai+1
 for all 1≤i<n
.

Input
The first line contains an integer t
 (1≤t≤104
)  — the number of test cases.

The first line of each test case contains three integers, n
, m
, and q
 (2≤n≤105
, 2≤m≤5⋅105
, 1≤q≤105
) — the size of the array a
, the integer m
, and the number of queries.

The second line of each test case contains n
 integers, a1,a2,…,an
 (0≤ai<m
).

Then follows q
 lines. Each line is of one of the following forms:

1
 i
 x
 (1≤i≤n
, 0≤x<m
)
2
 k
 (1≤k<m
)
It is guaranteed that the sum of n
 and the sum of q
 over all test cases each do not exceed 105
.

Output
For each instance of query 2
, output on a single line "YES" if there exists some sequence of (possibly zero) operations to make a
 nondecreasing, and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
2
7 6 6
4 5 2 2 4 1 0
2 4
1 4 5
2 4
2 3
1 7 2
2 3
8 8 3
0 1 2 3 4 5 6 7
2 4
1 3 4
2 4
OutputCopy
YES
NO
NO
YES
YES
NO
Note
In the first sample, the array is initially:

4	5	2	2	4	1	0
By applying the operation twice on a1
, twice on a2
, once on a5
, twice on a6
, and once on a7
, the array becomes:

0	1	2	2	2	3	4
which is in nondecreasing order.
After the second query, the array becomes:

4	5	2	5	4	1	0
and it can be shown that it is impossible to sort this with operations of the form ai:=(ai+4)(mod6)
, and it is also impossible to sort this with operations of the form ai:=(ai+3)(mod6)
.



#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n, m, q, op, i, x, k;
    cin >> n >> m >> q;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    map<int, int> ans;
    for(int i=1; i*i<=m; i++)
        if(!(m % i)){
            ans[i] = 0;
            ans[m/i] = 0;
        }
    for(pair<int, int> p : ans)
        for(int i=1; i<=n; i++)
            ans[p.first] += (a[i] % p.first < a[i-1] % p.first);
    while(q--){
        cin >> op;
        if(op == 1){
            cin >> i >> x;
            for(pair<int, int> p : ans){
                ans[p.first] += (x % p.first < a[i-1] % p.first) - (a[i] % p.first < a[i-1] % p.first);
                if(i != n)
                    ans[p.first] += (a[i+1] % p.first < x % p.first) - (a[i+1] % p.first < a[i] % p.first);
            }
            a[i] = x;
        }
        else{
            cin >> k;
            cout << (ans[__gcd(k, m)] < m / __gcd(k, m) ? "YES" : "NO") << '\n';
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
}
