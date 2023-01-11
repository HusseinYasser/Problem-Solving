
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    pair<int, bool> dfs(int node, int par, vector<int> adj[], vector<bool>& hasApple)
    {
        int ret = 1;

        bool apple = hasApple[node];

        for(auto ch : adj[node])
        {
            if(ch == par)
                continue;

            pair<int, bool> p = dfs(ch, node, adj, hasApple);
            apple |= p.second;
            if(p.second)
                ret += p.first+1;
        }

        return {ret, apple};
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        vector<int> adj[n];

        for(auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        return dfs(0, -1, adj, hasApple).first - 1;



    }
};