D. Price Tags
time limit per test2 seconds
memory limit per test256 megabytes
Imagine that you are the owner of a store. Before the start of a new season, you decided to clear your store of leftover goods, and therefore you decided to hold a total sale.

You have n
 different items in your store: the i
-th item costs ci
 coins. Each item has a price tag with the corresponding price ci
. You decided to hold a sale in the format: "we divided all the prices x
 times." Formally, this means that you choose a common coefficient x
, and during the sale, the i
-th item will cost ⌈cix⌉
 coins (where ⌈y⌉
 denotes rounding up).

To avoid confusion among the customers, you need to pin new price tags with new prices on all items, but printing new price tags is costly. Specifically, each printed price tag will cost you y
 coins.

Therefore, you had a brilliant idea — why not use the existing price tags and simply repin them on other items? So, you'll need to print price tags only for those items that do not have a corresponding price tag available.

There remains one last question: by how much should you reduce the prices, or what x
 should you choose? The coefficient x
 must be an integer strictly greater than 1
 and such that the total income is maximized. The total income is equal to the total value of the items minus the cost of the printed price tags.

Determine the maximum possible total income.

Input
The first line contains a single integer t
 (1≤t≤10
) — the number of test cases.

The first line of each test case contains two integers n
 and y
 (1≤n≤2⋅105
; 1≤y≤109
) — the number of items and the cost of printing one price tag.

The second line contains n
 integers c1,c2,…,cn
 (1≤ci≤2⋅105
) — the initial prices of the items.

Output
For each test case, output a single integer — the maximum total income.

Example
InputCopy
4
5 51
50 150 50 148 150
3 1000000000
42 42 42
10 54321
1 8088 45 1 73 1 9198 4991 1 83
3 100
1 1 1
OutputCopy
31
-2999999937
-162755
3
Note
In the first test case, it is optimal to choose x=3
. The new prices of the items will be [17,50,17,50,50]
. In this case, we can use two old price tags of 50
, and we will have to print three price tags for 17
, 17
, and 50
. As a result, the income will be 17+50+17+50+50−51⋅3=31
.

In the second test case, it is optimal to choose x=2
. The new prices will be [21,21,21]
, and we will have to print 3
 new price tags.

In the third test case, it is optimal to choose x=111
.

In the fourth test case, it is optimal to choose x=2
. The new prices will be the same as the old ones, so no new price tags will be printed.#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, y;
        cin >> n >> y;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int A = *max_element(a.begin(), a.end()) + 1;

        vector<long long> cntTags(A, 0), pSum(A, 0);

        for (int v : a) cntTags[v]++;

        for (int i = 1; i < A; i++) 
            pSum[i] = pSum[i - 1] + cntTags[i];

        long long ans = -1e18;

        if (A == 2) {
            cout << n << "\n";
            continue;
        }

        for (int x = 2; x < A; x++) {
            long long res = 0;
            for (int price = 1; price < A; price++) {
                long long l = 1LL * x * (price - 1);
                long long r = min((long long)A - 1, 1LL * x * price);
                if (l >= A) break;
                long long cnt = pSum[r] - pSum[l];
                res += cnt * price;
                res -= 1LL * y * max(0LL, cnt - cntTags[price]);
            }
            ans = max(ans, res);
        }

        cout << ans << "\n";
    }

    return 0;
}
