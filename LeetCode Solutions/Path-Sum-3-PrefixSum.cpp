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

    void dfs(TreeNode* root, int targetSum, map<long long,int>prefixSum, long long currSum, int& ans)
    {
        if(root == NULL)
            return;
        currSum += root->val;
        ans += prefixSum[currSum - targetSum];
        prefixSum[currSum]++;
        dfs(root->left, targetSum, prefixSum, currSum, ans);
        dfs(root->right, targetSum, prefixSum, currSum, ans);
    }

    int pathSum(TreeNode* root, int targetSum) {
        map<long long, int>prefixSum;
        prefixSum[0]++;
        int ans = 0;
        dfs(root, targetSum, prefixSum, 0ll, ans);
        return ans;

    }
};

