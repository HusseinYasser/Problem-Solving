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
        this->value = value;
        is_terminal = 0;
        for(int i = 0; i < 26; ++i)
            arr[i] = NULL;
    }
};

class Trie
{
public:

    Node* root;

    Trie()
    {
        root = new Node('\0');
    }

    void addWord(string word)
    {
        Node* tmp = root;
        for(auto ch : word)
        {
            if(tmp->arr[ch-'a'] == NULL)
                tmp->arr[ch-'a'] = new Node(ch);
            tmp = tmp->arr[ch-'a'];
        }
        tmp->is_terminal = 1;
    }

    bool findWord(Node* root, int i, string word)
    {
        if(i == word.length())
            return root->is_terminal;
        if(word[i] != '.')
        {
            if(root->arr[word[i] - 'a'] == NULL)
                return 0;
            return findWord(root->arr[word[i]-'a'], i+1, word);
        }
        else
        {
            bool ret = 0;
            for(int j = 0; j < 26; ++j){
                if(root->arr[j] != NULL){
                    ret |= findWord(root->arr[j], i+1, word);
                    if(ret)
                        return 1;
                }
            }
            return 0;
        }
    }
};


class WordDictionary {
public:

    Trie* trie;

    WordDictionary() {
        trie = new Trie();
    }

    void addWord(string word) {
        trie->addWord(word);
    }

    bool search(string word) {
        return trie->findWord(trie->root, 0, word);
    }
};
]

