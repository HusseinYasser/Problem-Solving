/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* solve(int lo, int hi, unordered_map<int, int>& mp)
    {
        if(lo > hi)
            return NULL;
        int mid = (lo + hi)>>1;
        TreeNode* curr = new TreeNode(mp[mid]);
        curr->left = solve(lo, mid-1, mp);
        curr->right = solve(mid + 1, hi, mp);
        return curr;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        unordered_map<int, int> mp;
        ListNode* curr = head;
        int i = 0;
        while(curr != NULL)
        {
            mp[i++] = curr->val;
            curr = curr->next;
        }
        return solve(0, i-1, mp);
    }
};
