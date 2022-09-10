#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int solve(TreeNode* root, int& ans)
    {
        if(root == NULL)
            return 0;
        int leftH = solve(root->left, ans), rightH = solve(root->right, ans);
        ans = max(leftH + rightH, ans);
        return 1 + max(leftH , rightH);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        //Diameter of the tree is the lowest point of the left subtree and the right subtree of all maximums
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};

