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

    bool same(TreeNode* root, TreeNode* sub)
    {
        if(root == NULL)
        {
            if(sub != NULL)
                return 0;
            return 1;
        }
        if(sub == NULL)
            return 0;
        return (root->val == sub->val) && same(root->left, sub->left) && same(root->right, sub->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL)
            return 0;
        if(same(root, subRoot))
            return 1;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};