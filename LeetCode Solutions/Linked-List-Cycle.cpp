#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return 0;
        ListNode* fast = head;
        ListNode* slow = head;
        while(1)
        {
            fast = (fast->next != NULL)? fast->next->next : NULL;
            slow = slow->next;
            if(fast == NULL)
                return 0;
            if(slow == fast)
                return 1;
        }
        return 1;
    }
};

