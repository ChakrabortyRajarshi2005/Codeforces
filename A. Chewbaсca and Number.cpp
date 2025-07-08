A. Chewbaсca and Number
time limit per test1 second
memory limit per test256 megabytes
Luke Skywalker gave Chewbacca an integer number x. Chewbacca isn't good at numbers but he loves inverting digits in them. Inverting digit t means replacing it with digit 9 - t.

Help Chewbacca to transform the initial number x to the minimum possible positive number by inverting some (possibly, zero) digits. The decimal representation of the final number shouldn't start with a zero.

Input
The first line contains a single integer x (1 ≤ x ≤ 1018) — the number that Luke Skywalker gave to Chewbacca.

Output
Print the minimum possible positive number that Chewbacca can obtain after inverting some digits. The number shouldn't contain leading zeroes.

Examples
InputCopy
27
OutputCopy
22
InputCopy
4545
OutputCopy
4444

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;
const double EPS = 1e-9;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

template <typename T>
void print_vector(const vector<T> &v) {
    for (int i = 0; i < sz(v); i++) {
        cout << v[i];
        if (i < sz(v) - 1)
            cout << " ";
    }
    cout << "\n";
}

template <typename T>
T gcd(T a, T b) {
    return b == 0 ? a : gcd(b, a % b);
}

template <typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

ll power(ll base, ll exp, ll mod = MOD) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void solve() {
    string x;
    cin >> x;

    for (size_t i = 0; i < x.length(); i++) {
        int digit = x[i] - '0';
        int inverted = 9 - digit;

        if (i == 0 && digit == 9)
            continue;

        if (inverted < digit)
            x[i] = '0' + inverted;
    }

    cout << x << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
