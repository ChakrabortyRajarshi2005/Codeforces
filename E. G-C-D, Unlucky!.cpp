E. G-C-D, Unlucky!
time limit per test2 seconds
memory limit per test256 megabytes
Two arrays p
 and s
 of length n
 are given, where p
 is the prefix GCD∗
 of some array a
, and s
 is the suffix GCD of the same array a
. In other words, if the array a
 existed, then for each 1≤i≤n
, the following equalities would hold both:

pi=gcd(a1,a2,…,ai)
si=gcd(ai,ai+1,…,an)
.
Determine whether there exists such an array a
 for which the given arrays p
 and s
 can be obtained.
∗
gcd(x,y)
 denotes the greatest common divisor (GCD) of integers x
 and y
.

Input
The first line contains an integer t
 (1≤t≤104
) — the number of test cases.

Each test case consists of three lines:

The first line of each test case contains a single integer n
 (1≤n≤105
) — the length of the array.

The second line of each test case contains n
 integers p1,p2,…,pn
 (1≤pi≤109
) — the elements of the array.

The third line of each test case contains n
 integers s1,s2,…,sn
 (1≤si≤109
) — the elements of the array.

It is guaranteed that the sum of all n
 across all test cases does not exceed 105
.

Output
For each test case, output "Yes" (without quotes) if there exists an array a
 for which the given arrays p
 and s
 can be obtained, and "No" (without quotes) otherwise.

You may output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

Example
InputCopy
5
6
72 24 3 3 3 3
3 3 3 6 12 144
3
1 2 3
4 5 6
5
125 125 125 25 25
25 25 25 25 75
4
123 421 282 251
125 1981 239 223
3
124 521 125
125 121 121
OutputCopy
YES
NO
YES
NO
NO
Note
For the first test case, a possible array is: [72, 24, 3, 6, 12, 144
].

For the second test case, it can be shown that such arrays do not exist.

For the third test case, there exists an array: [125, 125, 125, 25, 75
].
#include <bits/stdc++.h>
using namespace std;
main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long a[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        long long b[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        long long ans[n + 1];
        for (int i = n; i >= 1; i--) {
            ans[i] = lcm(a[i], b[i]);
        }
        bool ch = 1;
        if(ans[1] != a[1]) ch = 0;
        if(ans[n] != b[n]) ch = 0;
        for (int i = 2; i <= n; i++) {
            if (__gcd(a[i &mdash; 1], ans[i]) != a[i]) {
                ch = 0;
            }
        }
        for (int i = n &mdash; 1; i >= 1; i--) {
            if (__gcd(b[i + 1], ans[i]) != b[i]) {
                ch = 0;
            }
        }
        if (ch) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}
