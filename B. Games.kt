B. Games
time limit per test2 seconds
memory limit per test256 megabytes
Alice and Bob are planning to play an online game together but haven't decided on which one yet. Alice has a list of n
 games she enjoys: a1,a2,…,an
. Bob, on the other hand, has a list of m
 games he likes: b1,b2,…,bm
. They share at least one game in common between their lists.

To choose a game, they take turns suggesting games from their lists. Alice begins by suggesting one of her favorite games. If Bob likes it, they play that game. If not, Bob suggests one of his favorite games. If Alice likes it, they play that game. This alternating process continues, with Alice and Bob each suggesting games from their lists in turn, ensuring that no game is suggested more than once.

Your task is to calculate the maximum possible number of suggestions they will make while choosing which game to play.

Input
The first line contains a single integer t
 (1≤t≤1000
) — the number of test cases.

The first line of each test case contains two integers n
 and m
 (1≤n,m≤100
).

The second line contains n
 integers a1<a2<⋯<an
 (1≤ai≤100
).

The third line contains m
 integers b1<b2<⋯<bm
 (1≤bi≤100
).

Arrays a
 and b
 contain at least one common integer.

Output
For each test case, print a single integer — the maximum possible number of suggestions they will make while choosing which game to play.

Example
InputCopy
3
2 3
1 2
2 3 5
1 1
5
5
4 2
1 3 4 7
4 6
OutputCopy
3
1
4
Note
In the first test case, the maximum number of suggestions is 3
. It is achieved as follows:

Alice suggests game 1
, but Bob does not like it;
Bob suggests game 5
, but Alice does not like it;
Alice suggests game 2
, which Bob likes, and they go to play that game.
In the second test case, Alice can only suggest game 5
, which Bob likes, so they will immediately go to play it.

In the third test case, the maximum number of suggestions is 4
. It is achieved as follows:

Alice suggests game 7
, but Bob does not like it;
Bob suggests game 6
, but Alice does not like it;
Alice suggests game 1
, but Bob does not like it;
Bob suggests game 4
, which Alice likes, and they go to play it.


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int j = 0; j < m; j++) cin >> b[j];

        // Find intersection size
        unordered_set<int> setA(a.begin(), a.end());
        int k = 0;
        for (int x : b) {
            if (setA.count(x)) k++;
        }

        int result = 2 * min(n - k, m - k) + (n > m ? 2 : 1);
        cout << result << "\n";
    }

    return 0;
}
fun main() = repeat(readln().toInt()) { val (n, m) = readln().split(" ").map { it.toInt() } val a = readln().split(" ").map { it.toInt() } val b = readln().split(" ").map { it.toInt() } val k = a.intersect(b).size println(2 * minOf(n - k, m - k) + if (n > m) 2 else 1) }
