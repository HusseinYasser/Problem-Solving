#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<int> dfs(int root, int par, vector<int> adj[], string& labels, vector<int>& ans)
    {

        vector<int> ret(26, 0);

        ret[labels[root] - 'a']++;

        for(auto ch : adj[root])
        {
            if(ch == par)
                continue;

            vector<int> tmp = dfs(ch, root, adj, labels, ans);
            for(int i = 0; i < 26; ++i)
                ret[i] += tmp[i];
        }

        ans[root] = ret[labels[root] - 'a'];

        return ret;

    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {

        vector<int> adj[n];

        for(auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> ans(n, 0);

        dfs(0, -1, adj, labels, ans);

        return ans;

    }
};