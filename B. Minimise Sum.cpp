B. Minimise Sum
time limit per test1.5 seconds
memory limit per test256 megabytes
This problem differs from problem G. In this problem, you must output the minimum sum of prefix minimums after at most one operation.

You are given an array a
 of length n
, with elements satisfying 0≤ai≤n
. You can perform the following operation at most once:

Choose two indices i
 and j
 such that i<j
. Set ai:=ai+aj
. Then, set aj=0
.
Output the minimum possible value of min(a1)+min(a1,a2)+…+min(a1,a2,…,an)
 that you can get.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains an integer n
 (2≤n≤2⋅105
) — the length of a
.

The following line contains n
 space-separated integers a1,a2,…,an
 (0≤ai≤n
) — denoting the array a
.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output an integer on a new line, the minimum possible value of min(a1)+min(a1,a2)+…+min(a1,a2,…,an)
.

Example
InputCopy
3
2
1 2
3
1 2 3
4
3 0 2 3
OutputCopy
2
2
3
Note
In the second test case, it is optimal to perform the operation with i=2
 and j=3
.

In the third test case, it is optimal to not perform any operations. The answer is 3
.




#include <iostream>
#include <vector>
#include <algorithm>  // for std::min
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int n;
        cin >> n;  // Size of array
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << min(2 * a[0], a[0] + a[1]) << endl;
    }
    return 0;
}
