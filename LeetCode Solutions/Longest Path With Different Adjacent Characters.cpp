#include<bits/stdc++.h>

using namespace std;

class Compare{
public:

    bool operator()(int a, int b)
    {
        return a > b;

    }
};

class Solution {
public:

    int dfs(int node, int par, vector<int> adj[], string& s, int& ans)
    {

        priority_queue<int, vector<int>, Compare> pq;
        for(auto ch : adj[node])
        {
            if(ch == par)
                continue;

            int x = dfs(ch, node, adj, s, ans);

            if(s[node] != s[ch])
                pq.push(x);

            if(pq.size() > 2)
                pq.pop();
        }

        int ret = 1;
        int answer = 1;
        if(pq.size() > 0)
        {
            if(pq.size() == 1)  ret += pq.top();
            answer += pq.top();
            pq.pop();
        }

        if(pq.size() > 0){
            answer += pq.top();
            ret += pq.top();
        }

        ans = max(answer, ans);

        return ret;

    }

    int longestPath(vector<int>& parent, string s) {

        vector<int>adj[parent.size()];

        for(int i = 0; i < parent.size(); ++i)
        {
            if(parent[i] == -1)
                continue;

            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }

        int ans = 0;
        dfs(0, -1, adj, s, ans);

        return ans;
    }
};