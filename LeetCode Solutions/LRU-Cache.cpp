#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    int key;
    Node* next;
    Node* prev;

    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class List
{
public:
    Node* head;
    Node* tail;

    List()
    {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void delNode(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

class LRUCache {
public:


    List* list;
    unordered_map<int, Node*>mp;
    int capacity;


    LRUCache(int capacity) {
        list = new List();
        this->capacity = capacity;
    }


    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        int ret = mp[key]->val;
        list->delNode(mp[key]);
        list->addNode(mp[key]);
        return ret;
    }

    void put(int key, int value) {
        Node* node;
        if(mp.find(key) == mp.end())
        {
            node = new Node(key, value);
        }
        else{
            node = mp[key];
            node->val = value;
            list->delNode(node);
        }
        list->addNode(node);
        mp[key] = node;
        if(mp.size() > capacity)
        {
            //delete the excess node
            Node* deleted = list->tail->prev;
            int keyToBeRemoved = deleted->key;
            list->delNode(deleted);
            mp.erase(keyToBeRemoved);
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

