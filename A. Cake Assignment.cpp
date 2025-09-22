A. Cake Assignment
time limit per test2 seconds
memory limit per test256 megabytes
Chocola and Vanilla love cakes. Today, the manager of a cake shop gave them a total of 2k+1
 cakes. The cakes were distributed evenly, so each of them initially received 2k
 cakes.

However, Chocola and Vanilla now want to redistribute the cakes such that Chocola ends up with exactly x
 cakes and Vanilla gets the remaining 2k+1−x
 cakes.

In one step, they can perform exactly one of the following two operations:

Chocola gives half of her cakes to Vanilla. This operation is only allowed if Chocola currently has an even number of cakes.
Vanilla gives half of her cakes to Chocola. This operation is only allowed if Vanilla currently has an even number of cakes.
Your task is to determine the minimum number of steps required to reach the target distribution and to output any valid sequence of operations achieving that minimum.

It can be proven that, under the given constraints, a valid solution always exists, and the minimum number of steps required is at most 120
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤1000
). The description of the test cases follows.

The first line of each test case contains two integers k
 and x
 (1≤k≤60
, 1≤x≤2k+1−1
) — each person initially received 2k
 cakes, and x
 is the number of cakes Chocola should have after redistribution.

Output
For each test case, output a single integer n
 (0≤n≤120
) representing the minimum number of steps required for them to redistribute the cakes accordingly.

On the next line, output n
 integers o1,o2,…,on
 (oi=1
 or oi=2
), where oi=1
 means that in the i
-th step, Chocola gave half of her cakes to Vanilla (operation 1), and oi=2
 means that Vanilla gave half of her cakes to Chocola (operation 2).

Example
InputCopy
4
2 3
2 4
3 7
2 5
OutputCopy
2
2 1 
0

3
2 2 1 
2
1 2 
Note
In the first test case, they can use the following steps so that Chocola has exactly x=3
 cakes and Vanilla has exactly 2k+1−x=5
 cakes. We use {a,b}
 to denote that Chocola currently has a
 cakes and Vanilla currently has b
 cakes.

{4,4}−→−−o1=2{6,2}−→−−o2=1{3,5}

In the second test case, Chocola already has exactly x=4
 cakes and Vanilla already has exactly 2k+1−x=4
 cakes, so no operations are required.

In the third test case, they can use the following steps so that Chocola has exactly x=7
 cakes and Vanilla has exactly 2k+1−x=9
 cakes.

{8,8}−→−−o1=2{12,4}−→−−o2=2{14,2}−→−−o3=1{7,9}



#include <bits/stdc++.h> 
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        long long k,x,kk; cin>>k>>x; kk=1ll<<k;
        if (!x||x==kk*2) {cout<<"-1\n"; continue;}
        long long y=kk*2-x;
        vector<int> ans; ans.clear();
        while(x!=kk){
            if (x>y) ans.push_back(2),x-=y,y*=2;
            else ans.push_back(1),y-=x,x*=2;
        }
        cout<<ans.size()<<"\n";
        while(!ans.empty()) cout<<ans.back()<<' ',ans.pop_back();
        cout<<"\n";
    }
    return 0;
}
