#include<bits/stdc++.h>

using namespace std;


class Node
{
public:

    char val;
    int score = 0;

    Node* arr[26];

    Node(char ch)
    {
        val = ch;
        for(int i = 0; i < 26; ++i)
            arr[i] = NULL;
    }

};

class Trie
{
public:

    Node* head;

    unordered_map<string, int> mp;

    Trie()
    {
        head = new Node('\0');

        mp.clear();
    }

    void insert(string str, int val)
    {
        Node* node = head;

        for(auto ch : str)
        {
            if(node->arr[ch - 'a'] == NULL)
                node->arr[ch - 'a'] = new Node(ch);
            node->score += val - mp[str];
            node = node->arr[ch - 'a'];
        }
        node->score += val - mp[str];
        mp[str] = val;
    }

    int getAnswer(string prefix)
    {
        Node* node = head;

        for(auto ch : prefix)
        {
            if(node->arr[ch - 'a'] == NULL)
                return 0;

            node = node->arr[ch - 'a'];
        }

        return node->score;
    }

};

class MapSum {
public:

    /*
    Make a Trie and on every insert you adjust your nodes and finally in the get Request just traverse
    the trie till the node you need and get it's value
    */

    /*
    Also we need to check in case of updating the score of a string and this will require more space
    and a map to check over that

    */

    Trie* trie;

    MapSum() {

        trie = new Trie();
    }

    void insert(string key, int val) {
        trie->insert(key, val);
    }

    int sum(string prefix) {
        return trie->getAnswer(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */