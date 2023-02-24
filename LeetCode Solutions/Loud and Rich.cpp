#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    pair<int, int> dfs(int node, vector<int> adj[], bool vis[], vector<int>& quiet, vector<pair<int,int>>& answer)
    {

        vis[node] = 1;

        int ret = node;

        int q = quiet[node];

        for(auto ch : adj[node])
        {
            if(!vis[ch])
            {
                dfs(ch, adj, vis, quiet, answer);
            }
            pair<int, int> p = answer[ch];
            if(q > p.second)
            {
                q = p.second;
                ret = p.first;
            }
        }

        return answer[node] = {ret, q};


    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

        //O(V+E) One Traversal Go to the nodes in the order of richer and collect the data you want

        vector<int> adj[quiet.size()];

        bool vis[quiet.size()];

        for(int i = 0; i < quiet.size(); ++i)
            vis[i] = 0;

        for(auto e : richer)
        {
            adj[e[1]].push_back(e[0]);
        }

        vector<pair<int,int>> answer(quiet.size());

        for(int i = 0; i < quiet.size(); ++i)
        {
            if(!vis[i])
                dfs(i, adj, vis, quiet, answer);
        }

        vector<int> ret;
        for(auto p : answer)
            ret.push_back(p.first);

        return ret;
    }
};