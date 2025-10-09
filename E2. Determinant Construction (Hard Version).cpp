E2. Determinant Construction (Hard Version)
time limit per test5 seconds
memory limit per test256 megabytes

This is the hard version of the problem. The difference between the versions is that in this version, the constraints on the side length of M
 is smaller and the constraints on t
 is larger. You can hack only if you solved all versions of this problem.

You are given a non-negative integer x
. Your task is to construct a square matrix M
 that satisfies all of the following conditions:

The side length of M
 is at most 50
.
Each element of M
 is either −1
, 0
, or 1
.
The determinant of M
 is equal to x
.
Each row of M
 can have at most 3
 non-zero positions, and each column of M
 can have at most 3
 non-zero positions.
It can be proven that such a matrix always exists.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤500
). The description of the test cases follows.

The first and only line of each test case contains an integer x
 (0≤x≤107
) — the target value of the determinant.

Output
For each test case, output a single integer n
 (1≤n≤50
) representing the side length of the square matrix M
.

Then, output n
 lines, the i
-th line containing n
 integers Mi,1,Mi,2,…,Mi,n
 (Mi,j∈{−1,0,1}
), representing the elements of matrix M
.

If there are multiple matrices M
 satisfying the conditions, you may output any of them.

Example
InputCopy
3
1
2
4
OutputCopy
1
1
2
1 -1 
1 1 
5
1 -1 0 0 0 
1 1 1 0 0 
0 1 1 -1 0 
0 0 1 1 -1 
0 0 0 1 1 
Note
Note that in the third test case, the following solution:
⎛⎝⎜⎜⎜1−1111−1−1−1−1−10−111−1−1⎞⎠⎟⎟⎟
is not valid as there are four non-zero positions in the first row of the matrix.#include<bits/stdc++.h>
using namespace std;
int fl[1005],inf=1e9,cnt;
int work(int x,int y){
    int ans=0,tmp;
    while(y&&ans<=50){
        ++ans; tmp=y;
        if (x>y) y=x-y; else y=y-x;
        x=tmp;
    }
    if (x>1) return inf;
    return ans;
}
void gen(int x,int y){
    //printf("%d\n",work(x,y));
    vector<int> seq; seq.clear(); seq.push_back(x); seq.push_back(y);
    int tmp;
    while(!(x==2&&y==1)){
        tmp=y;
        if (x>y) y=x-y; else y=y-x;//x=tmp;
        x=tmp; 
        seq.push_back(y);
    }
    int ans[55][55]={0};
    int pre=seq.back(),n=1; seq.pop_back(); ans[1][1]=1;
    while(!seq.empty()){
        ++n;
        if (seq.back()>pre) ans[n][n]=1,ans[n][n-1]=1,ans[n-1][n]=-1;
        else ans[n][n]=1,ans[n][n-1]=1,ans[n-1][n]=1;
        pre=seq.back(); seq.pop_back();
    }
    printf("%d\n",n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}
map<int,int> mp;
int main(){
    int _; cin>>_;
    while(_--){
        int n; cin>>n;
        if (n==0) {printf("1\n0\n"); continue;}
        if (n==1) {printf("1\n1\n"); continue;}
        if (mp[n]) {gen(n,mp[n]); continue;}
        double s=(sqrt(5)-1.0)/2.0;
        int st=s*n,l=max(1,st),r=n-1;
        //int l=1,r=n-1;
        int nowy,nows=50;
        if (n%2==0){
            if (l%2==0) ++l;
            for(int y=l;y<=r;y+=2){
                int tmp=work(n,y);
                if (tmp<=nows) {gen(n,y); mp[n]=y; break;}
            }
        }
        else{
            for(int y=l;y<=r;++y){
                int tmp=work(n,y);
                if (tmp<=nows) {gen(n,y); mp[n]=y; break;}
            }
        }
    }
    return 0;
}
