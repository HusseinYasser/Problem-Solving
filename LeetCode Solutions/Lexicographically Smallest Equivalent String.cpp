#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    char dfs(char node, map<char, vector<char>>& adj, map<char, bool>& vis)
    {
        vis[node] = 1;

        char ret = node;

        for(auto ch : adj[node])
        {
            if(vis[ch])
                continue;

            ret = min(ret, dfs(ch, adj, vis));
        }

        return ret;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        //graph modeeling and then dfs and check the smallest lexiographical char

        map<char, vector<char>> adj;

        for(int i = 0; i < s1.length(); ++i)
        {
            adj[s1[i]].push_back(s2[i]);

            adj[s2[i]].push_back(s1[i]);
        }

        string ans = "";

        for(auto ch : baseStr)
        {
            if(adj.find(ch) == adj.end())
                ans.push_back(ch);
            else{
                map<char, bool> vis;

                for(auto x : adj) vis[x.first] = 0;

                ans.push_back(dfs(ch, adj, vis));
            }
        }

        return ans;
    }
};