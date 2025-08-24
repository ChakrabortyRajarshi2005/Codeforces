E. Make it Zero
time limit per test2 seconds
memory limit per test256 megabytes
You are given an array a
, consisting of n
 positive integers. You are allowed to do the following operation:

Select an array b
 of size n
 such that the following properties hold:
0≤bi≤ai
 for each 1≤i≤n
There exists an index 1≤i<n
 such that b1+b2+…+bi=bi+1+bi+2+…+bn
. That is, the sum of the prefix of length i
 is equal to the sum of the suffix of length n−i
.
Then, subtract bi
 from ai
 for each 1≤i≤n
.
Your task is to change all the elements to 0
. Find the minimum number of operations required.

Then, output a way to perform the operations. If it is impossible to change all the elements of a
 to 0
 no matter how many operations are used, print −1
 instead. It can be shown that under the constraints of this problem, the smallest number of operations required is at most 17
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains an integer n
 (2≤n≤5⋅104
) — the length of the array a
.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤1012
) — denoting the array a
.

It is guaranteed that the sum of n
 over all test cases does not exceed 5⋅104
.

Output
For each test case, output −1
 if there is no solution.

Otherwise, first output an integer s
 (1≤s≤17
) – the minimum number of operations to change all the elements of a
 to 0
.

Then, in the next s
 lines, output n
 integers in each line b1,b2,…,bn(0≤bi≤ai)
 — denoting the array b
 for each operation.

After performing the operations, all the elements of a
 should be changed to 0
.

Example
InputCopy
3
3
1 2 3
2
2 5
4
5 3 1 5
OutputCopy
1
1 2 3
-1
2
3 1 1 1
2 2 0 4
Note
In the first test case, we can simply choose b=a
 in our operation. This is valid because b1+b2=b3
.

In the second test case, it can be proven that it is impossible to change all the elements of a
 to 0
.



#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
const ll MOD = 1E9 + 7;
const int INF = 1E9; const ll INFLL = 1E18;
 
int n;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    int T; cin >> T;
    for(int test = 1; test <= T; test++) {
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll sum = 0;
        for(ll i : a) {
            sum += i;
        }
        if(sum % 2) {
            cout << "-1\n";
            continue;
        }
        ll mx = 0;
        for(ll i : a) {
            mx = max(mx, i);
        }
        if(mx * 2 > sum) {
            cout << "-1\n";
            continue;
        }
        ll cur = 0; int ind = 0;
        for(; ind < n; ind++) {
            if(cur + a[ind] > sum / 2) {
                ind--;
                break;
            }
            cur += a[ind];
        }
        if(cur == sum / 2) {
            cout << "1\n";
            for(ll i : a) {
                cout << i << " ";
            }
            cout << "\n";
        } else {
            cout << "2\n";
            vector<ll> aa(n);
            ll extra = sum - 2 * cur;
            aa[ind + 1] = extra / 2;
            a[ind + 1] -= aa[ind + 1];
            extra /= 2;
            for(int i = n - 1; i > ind + 1 && extra; i--) {
                if(a[i] >= extra) {
                    aa[i] = extra;
                    a[i] -= extra;
                    extra = 0;
                } else {
                    aa[i] = a[i];
                    extra -= a[i];
                    a[i] = 0;
                }
            }
            for(int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
            for(int i = 0; i < n; i++) {
                cout << aa[i] << " ";
            }
            cout << "\n";
        }
    }
}
