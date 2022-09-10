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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*, int>>q;
        q.push({root, 1});
        vector<int>ans;
        if(root == NULL)
            return ans;
        int lastLvl = 1;
        pair<TreeNode*, int>prev;
        while(q.size() > 0)
        {
            pair<TreeNode*, int> curr = q.front();
            q.pop();
            if(curr.second != lastLvl){
                ans.push_back(prev.first->val);
                lastLvl++;
            }
            if(curr.first->left != NULL)
                q.push({curr.first->left, curr.second+1});
            if(curr.first->right != NULL)
                q.push({curr.first->right, curr.second+1});
            prev = curr;
        }
        ans.push_back(prev.first->val);
        return ans;
    }
};

