#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int dfs(int node, vector<int> adj[], int par, long long& ans, int seats)
    {
        int here = 1;
        for(auto ch : adj[node])
        {
            if(ch == par)
                continue;
            here += dfs(ch, adj, node, ans, seats);
        }

        if(node != 0 ) ans += (here + 0ll)/seats + ((here%seats == 0)? 0:1);

        return here;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {

        //we don't have cycles here just a tree
        // try to have each one returns a number and we check for the seats at it in that case
        // and we add to the number and always we have it right

        vector<int> adj[roads.size()+1];
        for(auto e : roads)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        long long ans = 0ll;

        dfs(0, adj, -1, ans, seats);

        return ans;

    }
};