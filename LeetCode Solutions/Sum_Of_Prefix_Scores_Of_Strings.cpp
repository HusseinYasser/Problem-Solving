#include<bits/stdc++.h>
using namespace std;

class Node
{
public:

    char val;
    int words;
    Node* arr[26];

    Node(char x)
    {
        val = x;
        words = 0;
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

    void addWord(string str)
    {
        Node* curr = root;
        for(auto ch : str)
        {
            if(curr->arr[ch - 'a'] == NULL)
            {
                curr->arr[ch - 'a'] = new Node(ch);
            }
            curr->arr[ch - 'a']->words++;
            curr = curr->arr[ch - 'a'];
        }
    }

    int traverse(string str)
    {
        Node* curr = root;
        int ret = 0;

        for(auto ch : str)
        {
            if(curr->arr[ch - 'a'] == NULL)
                return ret;

            ret += curr->arr[ch - 'a']->words;
            curr = curr->arr[ch - 'a'];
        }

        return ret;
    }

};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        //for each string loop over all other strings and for each pair get the longest prefix match between both strings

        //another solution could be a Trie but with storing at each node the number of words comming out of this node
        Trie* trie = new Trie();

        vector<int> ans(words.size(), 0);

        for(int i = 0; i < words.size(); ++i)
        {
            trie->addWord(words[i]);

        }
        for(int i = 0; i < words.size(); ++i)
        {
            ans[i] = trie->traverse(words[i]);

        }

        return ans;
    }
};