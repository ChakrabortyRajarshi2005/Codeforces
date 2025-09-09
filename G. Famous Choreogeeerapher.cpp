G. Famous Choreographer
time limit per test3 seconds
memory limit per test512 megabytes
As all programmers know, there are n×m
 ballerinas performing in a ballet, and their arrangement can be represented as a table with n
 rows and m
 columns. Each ballerina performs one of 26
 movements, which can be described by one of the English letters.

Choreographer Vadim wants to dispel this myth. To do this, he wants to stage a show in which all the ballerinas gracefully move to the opposite side of the stage from their starting positions. Programmers will find it easier to understand this movement as a 180∘
 rotation of the table. To maintain the sequence of visual storytelling in the ballet, the ballerinas perform this movement instantaneously, without stopping their movements, and the final arrangement is identical to the initial one.

Unfortunately, Vadim understands that with the current performance and the already planned arrangement of the ballerinas, such a maneuver will not be possible. Therefore, he is ready to invite more ballerinas to the performance. They can perform any movement and occupy any position, but they cannot stand between those already participating in a ballet. The most important thing is that in the end, a rectangular table is formed, possibly larger than the original one. Additionally, it is essential that at least one ballerina from the original arrangement moves to the position of one of the other ballerinas from the original arrangement or remains in her place. Please advise Vadim on the smallest number of ballerinas he will need to invite.

Input
Each test consists of several test cases. The first line contains a single integer t
 (1≤t≤105)
 — the number of test cases. The following lines describe the test cases.

In the first line of each set, two integers n
 and m
 are given — the number of rows and the number of columns of the table (1≤n,m≤106,1≤n⋅m≤106)
.

The next n
 lines of length m
 describe the movements of the ballerinas — the ballerina in the i
-th row and j
-th column performs the movement fij
, where fij
 — is a lowercase English letter.

It is guaranteed that the sum of n⋅m
 across all test cases does not exceed 106
.

Output
For each test case, output the minimum number of ballerinas that Vadim will need to invite.

Example
InputCopy
6
2 3
hey
hey
3 3
abc
def
ghi
3 2
af
fa
te
1 1
x
3 3
uoe
vbe
mbu
2 3
hyh
kop
OutputCopy
4
16
2
0
11
3
Note
In the first sample, you can invite 4 ballerinas and arrange them as follows:

h	e	y	e	h
h	e	y	e	h
In the second sample, you can invite 16 ballerinas and arrange them like this:

j	k	a	b	c
k	j	d	e	f
i	h	g	h	i
f	e	d	j	k
c	b	a	k	j
In the third sample, you can invite 2 ballerinas and arrange them like this:

e	t
a	f
f	a
t	e
Here, the invited ballerinas are marked in bold.
#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 998244353;
const int P[2] = { 107, 61 };
int BP[2];

long long bin_pow(long long a, int n) {
    long long ret = 1;
    while (n) {
        if (n & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return ret;
}

inline int add(int a, int b) {
    int res = a + b;
    if (res >= MOD) return res - MOD;
    return res;
}

inline int sub(int a, int b) {
    int res = a - b;
    if (res < 0) return res + MOD;
    return res;
}

inline int mult(int a, int b) {
    long long res = (long long)a * b;
    if (res >= MOD) return res % MOD;
    return res;
}

int main() {
    int t;
    cin >> t;
    
    BP[0] = bin_pow(P[0], MOD - 2);
    BP[1] = bin_pow(P[1], MOD - 2);
    vector <int> pows[2];
    vector <int> bpows[2];
    for (int j = 0; j < 2; j++) {
        pows[j].resize(1e6, 1);
        bpows[j].resize(1e6, 1);
        for (int i = 1; i < 1e6; i++) {
            pows[j][i] = mult(pows[j][i - 1], P[j]);
            bpows[j][i] = mult(bpows[j][i - 1], BP[j]);
        }
    }
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector <string> f(n);
        for (int i = 0; i < n; i++)
            cin >> f[i];
        
        vector <vector <int>> hash(n + 2, vector <int> (m + 2, 0));
        vector <vector <int>> bhash(n + 2, vector <int> (m + 2, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int cur = mult((f[i - 1][j - 1] - 'a' + 1), mult(pows[0][i - 1], pows[1][j - 1]));
                hash[i][j] = add(sub(add(hash[i - 1][j], hash[i][j - 1]), hash[i - 1][j - 1]), cur);
            }
        }
        for (int i = n; i >= 1; i--) {
            for (int j = m; j >= 1; j--) {
                int cur = mult((f[i - 1][j - 1] - 'a' + 1), mult(pows[0][n - i], pows[1][m - j]));
                bhash[i][j] = add(sub(add(bhash[i + 1][j], bhash[i][j + 1]), bhash[i + 1][j + 1]), cur);
            }
        }
        
        auto isp = [&](int x1, int y1, int x2, int y2) {
            int hsh = add(sub(sub(hash[x2][y2], hash[x1-1][y2]), hash[x2][y1-1]), hash[x1-1][y1-1]);
            int bhsh = add(sub(sub(bhash[x1][y1], bhash[x2+1][y1]), bhash[x1][y2+1]), bhash[x2+1][y2+1]);
            hsh = mult(hsh, mult(bpows[0][x1 - 1], bpows[1][y1 - 1]));
            bhsh = mult(bhsh, mult(bpows[0][n - x2], bpows[1][m - y2]));
            return hsh == bhsh;
        };
        
        int mn = n * m * 4;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (isp(1, 1, i, j)) mn = min(mn, (2 * n - i) * (2 * m - j));
                if (isp(1, j, i, m)) mn = min(mn, (2 * n - i) * (m + j - 1));
                if (isp(i, 1, n, j)) mn = min(mn, (n + i - 1) * (2 * m - j));
                if (isp(i, j, n, m)) mn = min(mn, (n + i - 1) * (m + j - 1));
            }
        }
        
        cout << mn - m * n << '\n';
    }
    
    return 0;
}
