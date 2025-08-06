C. Leftmost Below
time limit per test2 seconds
memory limit per test256 megabytes
Consider an array a1,…,an
. Initially, ai=0
 for every i
.

You can do operations of the following form.

You choose an integer x
 greater than min(a)
.
Then, i
 is defined as the minimum index such that ai<x
. In other words, i
 is the unique integer between 1
 and n
 inclusive such that ai<x
 and aj≥x
 for every 1≤j≤i−1
.
Finally, ai
 is incremented by x
.
For example, if a=[6,8,2,1]
 and you choose x=6
, then i
 will be equal to 3
 (since a1≥6
, a2≥6
, and a3<6
) and a
 will become [6,8,8,1]
.

You can do as many operations as you want. Can you reach a target array b1,…,bn
?

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤10000
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (2≤n≤200000
).

The second line of each test case contains n
 integers b1,b2,…,bn
 (1≤bi≤109
).

The sum of n
 over all test cases does not exceed 200000
.

Output
For each test case, print YES if you can reach the target array and NO otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
4
4
5 6 1 1
3
3 1 2
3
40 60 90
2
1 1
OutputCopy
YES
NO
NO
YES
Note
In the first test case, we can do the following sequence of operations:

we choose x=2
, a
 becomes [2,0,0,0]
we choose x=2
, a
 becomes [2,2,0,0]
we choose x=3
, a
 becomes [5,2,0,0]
we choose x=4
, a
 becomes [5,6,0,0]
we choose x=1
, a
 becomes [5,6,1,0]
we choose x=1
, a
 becomes [5,6,1,1]
In the second test case, we can prove there is no way to reach [3,1,2]
.

A. Recycling Center
time limit per test1 second
memory limit per test256 megabytes
In the recycling center, there are n
 trash bags, the i
-th bag has a weight of ai
. At each second, two actions will happen successively:

First, you must choose a trash bag and destroy it. It will cost 1
 coin if the weight of the trash bag is strictly greater than c
, and it will cost 0
 coins otherwise.
Then, the weight of each remaining trash bag will get multiplied by two.
What is the minimum number of coins you have to spend to get rid of all trash bags?
Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤1000
). The description of the test cases follows.

The first line of each test case contains two integers n
 and c
 (1≤n≤30
, 1≤c≤109)
.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤109
) — the weight of each trash bag.

Output
For each test case, you must output a single integer — the minimum number of coins you have to spend to destroy all trash bags.

Example
InputCopy
4
5 10
10 4 15 1 8
3 42
1000000000 1000000000 1000000000
10 30
29 25 2 12 15 42 14 6 16 9
10 1000000
1 1 1 1 1 1 1 1 1 864026633
OutputCopy
2
3
6
1
Note
In the following explanation:

Numbers in blue represent trash bags that have been destroyed for free,
Numbers in red represent trash bags that have been destroyed for 1
 coin,
Numbers in black represent trash bags that have not been destroyed yet.
In the first test case, one solution is:

[10,4,15,1,8]
[10,8,30,2,16]
, 10
 is destroyed for free because 10≤10
.
[10,8,60,4,32]
, 8
 is destroyed for free because 8≤10
.
[10,8,120,8,32]
, 32
 is destroyed for 1
 coin because 32>10
.
[10,8,240,8,32]
, 8
 is destroyed for free because 8≤10
.
[10,8,240,8,32]
, 240
 is destroyed for 1
 coin because 240>10
.
In total, you paid 2
 coins, and we can prove it is optimal.

In the second test case, one solution is:

[1000000000,1000000000,1000000000]
[1000000000,2000000000,2000000000]
, 1000000000
 is destroyed for 1
 coin because 1000000000>42
.
[1000000000,2000000000,4000000000]
, 2000000000
 is destroyed for 1
 coin because 2000000000>42
.
[1000000000,2000000000,4000000000]
, 4000000000
 is destroyed for 1
 coin because 4000000000>42
.



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while(T--) {
        int N, C;
        cin >> N >> C;
        vector<ll> A(N);
        for (ll &x : A) cin >> x;
        sort(A.rbegin(), A.rend()); // sort by decreasing order
        int saved = 0;
        for (ll x : A) {
            if (x*(1LL << saved) <= C) {
                ++saved;
            }
        }
        cout << N - saved << '\n';



      #include <bits/stdc++.h>
using namespace std;

bool solve() {
    int N; cin >> N;
    vector<int> B(N);
    for (int &x : B) cin >> x;
    int min_pref = B[0];
    for (int val : B) {
        if (val >= 2*min_pref) return false;
        min_pref = min(min_pref, val);
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
}
    }
}
