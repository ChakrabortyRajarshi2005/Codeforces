C. Divine Tree
time limit per test2 seconds
memory limit per test256 megabytes

Harshith attained enlightenment in Competitive Programming by training under a Divine Tree. A divine tree is a rooted tree∗
 with n
 nodes, labelled from 1
 to n
. The divineness of a node v
, denoted d(v)
, is defined as the smallest node label on the unique simple path from the root to node v
.

Aryan, being a hungry Competitive Programmer, asked Harshith to pass on the knowledge. Harshith agreed on the condition that Aryan would be given two positive integers n
 and m
, and he had to construct a divine tree with n
 nodes such that the total divineness of the tree is m
, i.e., ∑i=1nd(i)=m
. If no such tree exists, Aryan must report that it is impossible.

Desperate for knowledge, Aryan turned to you for help in completing this task. As a good friend of his, help him solve the task.

∗
A tree is a connected graph without cycles. A rooted tree is a tree where one vertex is special and called the root.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains two integers n
 and m
 (1≤n≤106
, 1≤m≤1012
).

It is guaranteed that the sum of n
 over all test cases does not exceed 106
.

Output
For each test case, output a single integer k
 in one line — the root of the tree.

Then n−1
 lines follow, each containing a description of an edge of the tree — a pair of positive integers ui,vi
 (1≤ui,vi≤n
, ui≠vi
), denoting the i
-th edge connects vertices ui
 and vi
.

The edges and vertices of the edges can be printed in any order. If there are multiple solutions, print any of them.

If there is no solution, print "-1" instead.

Example
InputCopy
2
1 2
4 6
OutputCopy
-1
3
3 1
1 2
2 4
Note
In the first test case, there is a single node with a value of 1
, so getting a sum of 2
 is impossible.

In the second test case, getting a sum of 6
 is possible with the given tree rooted at 3
.
#include <iostream>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    
    int l1, b1, l2, b2, l3, b3;
    
    auto check = [&] () {
        if (l1 == l2 && l2 == l3) return (l1 == b1 + b2 + b3 || (b1 == b2 + b3 && 2*l1 == b1));
        if (l2 == l3) return (b2 + b3 == b1 && b1 == l2 + l1);
        return false;
    };
    
    while(t--) {
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        if(check()) cout << "YES\n";
        else {
            swap(l1, b1); swap(l2, b2); swap(l3, b3);
            if(check()) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    
    return 0;
}
