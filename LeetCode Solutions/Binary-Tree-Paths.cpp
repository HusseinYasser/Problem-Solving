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

    void dfs(TreeNode* root, string curr, vector<string>& ans)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
        {
            curr += to_string(root->val);
            ans.push_back(curr);
            return;
        }
        dfs(root->left, curr + to_string(root->val) + "->", ans);
        dfs(root->right, curr + to_string(root->val) + "->", ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(root == NULL)
            return ans;
        string curr = "";
        dfs(root, curr, ans);
        return ans;
    }
};