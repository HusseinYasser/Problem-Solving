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

    long long solve(TreeNode* root,long long curr, int targetSum, bool taken, map<tuple<TreeNode*,int,bool>,long long>& memo)
    {
        long long ans = 0ll;
        if(curr == targetSum && taken)
            ans++;
        if(root == NULL)
            return ans;
        if(memo.find(make_tuple(root, curr, taken)) != memo.end()){
            return memo[make_tuple(root, curr, taken)];
        }
        if(!taken){
            ans += solve(root->left, curr, targetSum, 0, memo);
            ans += solve(root->right, curr, targetSum, 0, memo);
        }
        ans += solve(root->left,curr + root->val, targetSum, 1, memo);
        ans += solve(root->right, curr + root->val, targetSum, 1, memo);
        memo.insert({make_tuple(root, curr, taken), ans});
        return ans;
    }


    int pathSum(TreeNode* root, int targetSum) {
        map<tuple<TreeNode*, int, bool>,long long>memo;
        memo.clear();
        long long curr = 0ll;
        solve(root, curr, targetSum, 0, memo);
        return memo[make_tuple(root, 0, 0)]/2;

    }
};