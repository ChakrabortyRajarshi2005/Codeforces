Distribute Candies
Difficulty: HardAccuracy: 63.24%Submissions: 35K+Points: 8
You are given the root of a binary tree with n nodes, where each node contains a certain number of candies, and the total number of candies across all nodes is n. In one move, you can select any two adjacent nodes and transfer one candy from one node to the other. The transfer can occur between a parent and child in either direction.

The task is to determine the minimum number of moves required to ensure that every node in the tree has exactly one candy.

Note: The testcases are framed such that it is always possible to achieve a configuration in which every node has exactly one candy, after some moves.

Examples:

Input: root = [5, 0, 0, N, N, 0, 0]
  
Output: 6
Explanation:
Move 1 candy from root to left child
Move 1 candy from root to right child
Move 1 candy from right child to root->right->left node
Move 1 candy from root to right child
Move 1 candy from right child to root->right->right node
Move 1 candy from root to right child
so, total 6 moves required.
Input: root = [2, 0, 0, N, N, 3, 0]
  
Output: 4
Explanation:
Move 1 candy from root to left child
Move 1 candy from root->right->left node to root->right node
Move 1 candy from root->right node to root->right->right node
Move 1 candy from root->right->left node to root->right node
so, total 4 moves required.
Constraints:
1 ≤ n ≤ 3*103
0 ≤ Node->data ≤ n
The sum of all Node->data = n

class Solution {
    public int distCandyUtil(Node root, int[] ans) {
        if (root == null) return 0;

        int l = distCandyUtil(root.left, ans);
        int r = distCandyUtil(root.right, ans);

        ans[0] += Math.abs(l) + Math.abs(r);

        return root.data + l + r - 1;
    }

    public int distCandy(Node root) {
        int[] ans = new int[1];
        distCandyUtil(root, ans);
        return ans[0];
    }
}
