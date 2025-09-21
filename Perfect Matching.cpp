Perfect Matching
Chef constructed a tree with 
N
N vertices using the following process:

Generate a random array of size 
N
−
1
N−1 where 
1
≤
P
i
≤
i
1≤P 
i
​
 ≤i. All possible arrays satisfying the constraints are equally likely.
Create a tree with only 
1
1 vertex labelled 
1
1.
For each 
i
=
2
,
3
,
…
,
N
i=2,3,…,N, add a vertex labelled 
i
i to the tree, connected with an edge to 
P
i
−
1
P 
i−1
​
 .
Find the probability that this tree has a perfect matching. Output the probability modulo 
998244353
998244353. Formally, it can be proven that the answer can be represented as 
P
Q
Q
P
​
  where 
Q
m
o
d
 
 
998244353
≠
0
Qmod998244353=0, then print the unique integer 
R
R in 
[
0
,
998244353
)
[0,998244353) such that 
R
⋅
Q
=
P
(
m
o
d
 
 
998244353
)
R⋅Q=P(mod998244353).

A matching is a set of edges such that each vertex is adjacent to at most one edge. A graph is said to have a perfect matching if there is a matching such that each vertex is adjacent to exactly one edge.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
The first and only line of each test case contains a single integer 
N
N - the number of nodes in the tree.
Output Format
For each test case, output the probability of a perfect matching modulo 
998244353
998244353.

Constraints
1
≤
T
≤
100
1≤T≤100
1
≤
N
≤
10
4
1≤N≤10 
4
 
The sum of 
N
N over all test cases does not exceed 
10
4
10 
4
 
Sample 1:
Input
Output
6
1
2
3
4
6
9000
0
1
0
665496236
632221424
476507467
Explanation:
Test Case 1 : There is only one vertex, and that cannot be matched with anyone else.

Test Case 2 : The graph always has an edge 
(
1
,
2
)
(1,2), which can be chosen as the perfect matching.


import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    static int size = 10001;
    static long fact[] = new long[size];
    static long invFact[] = new long [size];
    static long mod = 998244353;
    
    public static void preCompute(){
        fact[0] = 1;
        
        for(int i=1;i<size;i++){
            fact[i] = (fact[i-1] * i) % mod;
        }
        
        invFact[size -1] = power(fact[size-1],mod-2) % mod;
        
        for(int i=size-2;i>=0;i--){
            invFact[i] = ((i+1) * invFact[i+1]) % mod;
        }
    }
    
    public static long power(long a , long b){
        if(b == 0){
            return 1;
        }
        
        long res = power(a , b/2) % mod;
        
        if(b % 2 == 0){
            res = (res * res) % mod;
            return res;
        }
        else{
            res = (res * res) % mod;
            res = (res * a) % mod;
            return res;
        }
    } 
    
    public static long nCr(long n , long r){
        if(n < r || r < 0){
            return 0;
        }
        
        long res = (fact[(int)n] * invFact[(int)(n-r)] ) % mod;
        res = (res * invFact[(int)r]) % mod;
        
        return res;
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        preCompute();
        
        while(t-- > 0){
            int n = sc.nextInt();
            
            if(n % 2 != 0){
                System.out.println("0");
                continue;
            }
            
            long dp[] = new long[n+1];
            dp[1] = 1;
            
            for(int i=2;i<=n;i++){
                for(int s = i-1;s>= 1 ; s-=(1 + i % 2)){
                    long ways = (dp[s] * dp[i-s]) % mod;
                    ways = (ways * nCr(i-2,s-1)) % mod;
                    dp[i] = (dp[i] + ways) % mod;
                }
            }
            System.out.println((dp[n] * invFact[n-1]) % mod);
        }
	}
}
