C. Gellyfish and Eternal Violet
time limit per test2 seconds
memory limit per test1024 megabytes

There are n
 monsters, numbered from 1
 to n
, in front of Gellyfish. The HP of the i
-th monster is hi
.

Gellyfish doesn't want to kill them, but she wants to keep these monsters from being a threat to her. So she wants to reduce the HP of all the monsters to exactly 1
.

Now, Gellyfish, with The Sword Sharpened with Tears, is going to attack the monsters for m
 rounds. For each round:

The Sword Sharpened with Tears shines with a probability of p
.
Gellyfish can choose whether to attack:
If Gellyfish doesn't attack, nothing happens.
If Gellyfish chooses to attack and The Sword Sharpened with Tears shines, the HP of all the monsters will be reduced by 1
.
If Gellyfish chooses to attack and The Sword Sharpened with Tears does not shine, Gellyfish can choose one of the monsters and reduce its HP by 1
.
Please note that before Gellyfish decides whether or not to attack, she will know whether the sword shines or not. Also, when the sword shines, Gellyfish can only make attacks on all the monsters and cannot make an attack on only one monster.

Now, Gellyfish wants to know what the probability is that she will reach her goal if she makes choices optimally during the battle.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤100
). The description of the test cases follows.

The first line of each test case contains three integers n
, m
, and p′
 (1≤n≤20
, 1≤m≤4000
, 0≤p′≤100
) — the number of monsters, the number of rounds of attacks, and an integer representing the probability p=p′100
 that the Sword Sharpened with Tears shines.

The second line of each test case contains n
 integers h1,h2,…,hn
 (1≤hi≤400
) — the HP of the monsters.

It is guaranteed that the sum of n
 over all test cases does not exceed 100
.

Output
For each test case, output a single real number representing the probability that Gellyfish will reach her goal.

Your answer is considered correct if its absolute or relative error does not exceed 10−6
.

Formally, let your answer be a
, and the jury's answer be b
. Your answer is accepted if and only if |a−b|max(1,|b|)≤10−6
.

Example
InputCopy
4
2 2 10
2 2
5 5 20
2 2 2 2 2
6 20 50
1 1 4 5 1 4
9 50 33
9 9 8 2 4 4 3 5 3
OutputCopy
0.910000
0.672320
0.588099
0.931474
Note
In the first test case, Gellyfish will always attack whether the sword shines or not in the first round.

If the sword shines in the first round, then Gellyfish can reach her goal after the attack in the first round.

Otherwise, if the sword does not shine in the first round, she will attack monster 1
 in the first round. For the second round:

If the sword shines, since monster 1
 was attacked in the first round, Gellyfish can't reach her goal.
Otherwise, Gellyfish can attack monster 2
, allowing her to reach her goal.
Therefore, the probability that Gellyfish can reach her goal is 10%+(90%⋅90%)=91%
.

In the second test case, Gellyfish will only attack in the first round where the sword shines. It can be observed that the only way Gellyfish can't reach her goal is if the sword never shines in all 5
 rounds. The probability that Gellyfish can reach her goal is 100%−(80%)5=67.232%
.


#include<bits/stdc++.h>

using namespace std;

const int N = 22, K = 4000 + 5, M = 400 + 5, Inf = 0x3f3f3f3f;

inline void checkmin(double &x, double y){
	if(y < x) x = y;
}

int n = 0, m = 0, s = 0, k = 0, p0 = 0, h[N] = {};
double p = 0, f[K][K] = {}, g[K][N][M] = {}, ans = 0;

inline void init(){
	for(int i = 0 ; i <= k ; i ++){
		for(int c = 0 ; c < n ; c ++) for(int x = 0 ; x <= m ; x ++) g[i][c][x] = 0;
		for(int x = 0 ; x <= s ; x ++) f[i][x] = 0;
	}
	m = Inf, s = 0, ans = 0;
}

inline void solve(){
	scanf("%d %d %d", &n, &k, &p0);
	p = 1.0 * p0 / 100;
	for(int i = 1 ; i <= n ; i ++){
		scanf("%d", &h[i]); h[i] --;
		m = min(m, h[i]);
	}
	for(int i = 1 ; i <= n ; i ++) s += h[i] - m;
	if(s > k){
	    printf("0.000000\n");
	    return;
	}
	g[0][0][0] = 1;
	for(int i = 1 ; i <= k ; i ++){
		g[i][0][0] = 1;
		for(int x = 1 ; x <= m ; x ++) g[i][0][x] = g[i - 1][0][x - 1] * p + max(g[i - 1][0][x], g[i - 1][n - 1][x - 1]) * (1 - p);
		for(int c = 1 ; c < n ; c ++){
			g[i][c][0] = g[i - 1][c][0] * p + g[i - 1][c - 1][0] * (1 - p);
			for(int x = 1 ; x <= m ; x ++) g[i][c][x] = g[i - 1][c][x - 1] * p + g[i - 1][c - 1][x] * (1 - p);
		}
	}
	f[0][0] = 1;
	for(int i = 0 ; i < k ; i ++) for(int x = 0 ; x < s ; x ++){
		f[i + 1][x] += f[i][x] * p;
		f[i + 1][x + 1] += f[i][x] * (1 - p);
	}
	for(int i = s ; i <= k ; i ++){
		double r = 0;
		for(int x = 0 ; x <= min(i - s, m) ; x ++) r = max(r, g[k - i][0][m - x]);
		ans += r * f[i][s];
	}
	printf("%.6lf\n", ans);
}

int T = 0;

int main(){
	scanf("%d", &T);
	while(T --) init(), solve();
	return 0;
}
