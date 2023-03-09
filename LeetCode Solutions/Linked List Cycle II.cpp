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
    ListNode *detectCycle(ListNode *head) {
        ListNode* tmp1 = head;
        ListNode* tmp2 = head;
        
        while(tmp1 != NULL && tmp2 != NULL )
        {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
            if(tmp2 == NULL)
                return tmp2;
            tmp2 = tmp2->next;
            if(tmp1 == tmp2)
                break;
        }
        if(tmp1 == NULL || tmp2 == NULL)
            return NULL;
        
        tmp1 = head;
        while(tmp1 != tmp2)
        {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        return tmp1;
        
    }
};
