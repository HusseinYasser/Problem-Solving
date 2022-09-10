#include<bits/stdc++.h>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node* ans = new Node(-1);
        unordered_map<Node*, Node*> mp;
        Node* tmp = head;
        Node* ansTemp = ans;
        while(tmp != NULL)
        {
            Node* newNode = new Node(tmp->val);
            mp.insert({tmp, newNode});
            ansTemp->next = newNode;
            tmp = tmp->next;
            ansTemp = ansTemp->next;
        }

        tmp = head;
        ansTemp = ans->next;
        while(tmp != NULL)
        {
            ansTemp->random = mp[tmp->random];
            ansTemp = ansTemp->next;
            tmp = tmp->next;
        }
        return ans->next;
    }
};