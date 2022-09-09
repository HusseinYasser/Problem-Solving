#include<bits/stdc++.h>

using namespace std;

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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return NULL;
        int sz = 0;
        ListNode* tmp = head;
        while(tmp != NULL)
        {
            tmp = tmp->next;
            sz++;
        }

        tmp = head;
        ListNode* ans = new ListNode(-1);
        ans->next = head;
        ListNode* prev = ans;
        while(sz-- > n)
        {
            tmp = tmp->next;
            prev = prev->next;
        }
        prev->next = tmp->next;
        return ans->next;
    }
};
