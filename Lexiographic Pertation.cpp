I. Lexicographic Partition
time limit per test2 seconds
memory limit per test256 megabytes

Given an array a
, define f(a)
 as follows:

Let k
 be an integer with 1≤k≤n
.
Partition a
 into k
 subarrays∗
 s1,s2,…,sk
 such that s1+s2+…+sk=a
. Here, +
 represents array concatenation.
Let b
 be an empty array. For each i
 from 1
 to k
 in order, append the minimum element of si
 to the end of b
.
Over all possible k
 and partitions, f(a)
 is the value of k
 such that there exists a partition that produces the lexicographically largest b
†
.
You are given n
 integers x1,x2,…,xn
. Please determine if there exists a permutation‡
 a
 such that f([a1,a2,…,ai])=xi
 for each 1≤i≤n
. If there is a permutation, print one. If there are multiple possible answers, you may output any one.

∗
An array c
 is a subarray of an array d
 if c
 can be obtained from d
 by the deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

†
An array c
 is lexicographically smaller than an array d
 if and only if one of the following holds:

c
 is a prefix of d
, but c≠d
; or
in the first position where c
 and d
 differ, the array c
 has a smaller element than the corresponding element in d
.
‡
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

The first line of each test case contains an integer n
 (2≤n≤2⋅105
) — denoting the length of the array x
.

The following line contains n
 integers x1,x2,…,xn
 (1≤xi≤i
) — denoting the array x
.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print YES if a permutation exists, and NO otherwise. Each letter may be outputted in uppercase or lowercase. You can output in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

If the answer is positive, output the permutation of n
 numbers on the next line.

Example
InputCopy
8
3
1 2 2
2
1 1
3
1 2 1
3
1 2 3
4
1 2 2 4
4
1 2 3 3
5
1 2 3 2 3
9
1 2 3 4 5 4 5 6 6
OutputCopy
YES
1 2 3
NO
NO
YES
3 1 2
NO
YES
3 1 2 4
YES
1 4 3 5 2
YES
5 2 1 8 6 9 3 4 7
Note
In the first test case, [1,2,3]
 is a valid permutation that satisfies the input array:

for [1]
, there is only one way to partition: partition a[1]
 by itself, so f([1])=1
.
for [1,2]
, there are two ways to partition: [1,2]
 by itself or [1]+[2]
. Constructing b
 from the first partition yields b=[1]
 and constructing b
 from the second partition yields b=[1,2]
. The second one is lexicographically larger, so f([1,2])=2
.
For [1,2,3]
, it can be shown the best partition is [1,2]+[3]
, yielding b=[1,3]
.
In the second test case, it can be


#include <bits/stdc++.h>
using namespace std;
#define int short
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    int n; cin >> n;
    
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    for (int i = n; i >= 1; i--){
        vector <int> good(n + 1, -1);
        int curr = a[i];
        
        dp[i][i] = curr;
        
        for (int j = i + 1; j <= n; j++){
            if (a[j] < a[i]){
                continue;
            }
            
            if (a[j] == a[i]){
                curr += 1;
                dp[i][j] = curr;
                continue;
            }
            
            if (good[a[j]] == -1 && a[j] <= curr + 1){
                good[a[j]] = j;
            }
            
            if (good[a[j]] != -1){
                int idx = good[a[j]];
                curr = max(curr, dp[idx][j]);
            }
        }
    }
    
    // for (int l = 1; l <= n; l++){
    //     for (int r = l; r <= n; r++){
    //         if (dp[l][r])
    //         cout << l << " " << r << " " << dp[l][r] << "\n";
    //     }
    // }
    
    int curr = 0;
    vector <int> good(n + 1, -1);
    for (int j = 1; j <= n; j++){
        if (good[a[j]] == -1 && a[j] <= curr + 1){
            good[a[j]] = j;
        }
        
        if (good[a[j]] != -1){
            int idx = good[a[j]];
            curr = max(curr, dp[idx][j]);
        }
    }
    
    cout << curr << "\n";
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}
