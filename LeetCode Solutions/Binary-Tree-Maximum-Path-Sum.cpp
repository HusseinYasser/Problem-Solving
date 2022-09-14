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

    int ans = INT32_MIN;

    int solve(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int left = solve(root->left), right = solve(root->right);
        ans = max(left + root->val, ans);
        ans = max(right + root->val, ans);
        ans = max(ans, root->val);
        ans = max(left + right + root->val, ans);
        int retBack = max(left, right);
        return ((retBack>=0)? retBack : 0) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        ans = INT32_MIN;
        solve(root);
        return ans;
    }
};
