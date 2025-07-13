F. Minimize Fixed Points
time limit per test3 seconds
memory limit per test256 megabytes
Call a permutation∗
 p
 of length n
 good if gcd(pi,i)
†
 >1
 for all 2≤i≤n
. Find a good permutation with the minimum number of fixed points‡
 across all good permutations of length n
. If there are multiple such permutations, print any of them.

∗
 A permutation of length n
 is an array that contains every integer from 1
 to n
 exactly once, in any order.

†
gcd(x,y)
 denotes the greatest common divisor (GCD) of x
 and y
.

‡
A fixed point of a permutation p
 is an index j
 (1≤j≤n
) such that pj=j
.

Input
The first line contains an integer t
 (1≤t≤104
)  — the number of test cases.

The only line of each test case contains an integer n
 (2≤n≤105
) — the length of the permutation.

It is guaranteed that the sum of n
 over all test cases does not exceed 105
.

Output
For each test case, output on a single line an example of a good permutation of length n
 with the minimum number of fixed points.

Example
InputCopy
4
2
3
6
13
OutputCopy
1 2
1 2 3
1 4 6 2 5 3
1 12 9 6 10 8 7 4 3 5 11 2 13
Note
In the third sample, we construct the permutation

i
pi
gcd(pi,i)
1
1
1
2
4
2
3
6
3
4
2
2
5
5
5
6
3
3
Then we see that gcd(pi,i)>1
 for all 2≤i≤6
. Furthermore, we see that there are only two fixed points, namely, 1
 and 5
. It can be shown that it is impossible to build a good permutation of length 6
 with fewer fixed poin


#include <bits/stdc++.h>
using namespace std;
 
vector<bool> comp(1e5+1);
vector<int> primes;
 
void sieve(){
    for(int i=2; i*i<=1e5; i++)
        if(!comp[i])
            for(int j=i*i; j<=1e5; j+=i)
                comp[j] = true;
    for(int i=2; i<=1e5; i++)
        if(!comp[i])
            primes.push_back(i);
}
 
void solve(){
    int n;
    cin >> n;
    vector<int> p(n+1);
    for(auto it = primes.rbegin(); it != primes.rend(); ++it){
        vector<int> cycle;
        for(int i=*it; i<=n; i+=*it)
            if(!p[i])
                cycle.push_back(i);
        for(int i=0; i<cycle.size(); i++)
            p[cycle[i]] = cycle[(i+1) % cycle.size()];
    }
    for(int i=1; i<=n; i++)
        if(!p[i])
            p[i] = i;
    for(int i=1; i<=n; i++)
        cout << p[i] << (i != n ? ' ' : '\n');
}
 
int main(){
    sieve();
    int t;
    cin >> t;
    while(t--) solve();
}
