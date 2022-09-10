#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root->val >= p->val && root->val <= q->val)
            return root;
        else if(root->val > q->val)
            return LCA(root->left, p, q);
        else
            return LCA(root->right, p, q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        return LCA(root, (p->val < q->val)? p:q,(q->val > p->val)? q:p);
    }
};

