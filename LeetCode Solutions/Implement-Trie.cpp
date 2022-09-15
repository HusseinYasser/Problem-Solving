#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    char value;
    bool is_terminal;
    Node* arr[26];

    Node(char value)
    {
        is_terminal = 0;
        this->value = value;
        for(int i = 0 ; i < 26; ++i)
            arr[i] = NULL;
    }
};

class Trie {
public:

    Node* root;

    Trie() {
        root = new Node('\0');
    }

    void insert(string word) {
        Node* tmp = root;
        for(auto ch : word)
        {
            if(tmp->arr[ch-'a'] == NULL)
                tmp->arr[ch-'a'] = new Node(ch);
            tmp = tmp->arr[ch-'a'];
        }
        tmp->is_terminal = 1;
    }

    bool search(string word) {
        Node* tmp = root;
        for(auto ch : word)
        {
            if(tmp->arr[ch-'a'] == NULL)
                return 0;
            tmp = tmp->arr[ch-'a'];
        }
        return tmp->is_terminal;
    }

    bool startsWith(string prefix) {
        Node* tmp = root;
        for(auto ch : prefix)
        {
            if(tmp->arr[ch-'a'] == NULL)
                return 0;
            tmp = tmp->arr[ch-'a'];
        }
        return 1;
    }
};



