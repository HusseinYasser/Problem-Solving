#include<bits/stdc++.h>

using namespace std;

class Solution {
public:


    bool dfs(int node, vector<vector<int>>&adj, int vis[])
    {
        bool ret = 1;
        for(auto ch : adj[node])
        {
            if(vis[ch] == vis[node])
                return 0;
            else if(!vis[ch]){
                vis[ch] = 3 - vis[node];
                ret&=dfs(ch, adj, vis);
            }
        }
        return ret;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int vis[graph.size()];
        for(int i = 0; i < graph.size(); ++i)
            vis[i] = 0;

        for(int i = 0; i < graph.size(); ++i)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                bool b = dfs(i, graph, vis);
                if(!b)
                    return 0;
            }

        }

        return 1;

    }
};