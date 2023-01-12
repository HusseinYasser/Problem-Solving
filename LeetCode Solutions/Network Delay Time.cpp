#include <bits/stdc++.h>

using namespace std;


class Compare
{
public:
    bool operator() (pair<int,int> p1, pair<int,int> p2)
    {
        return p1.second > p2.second;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>>adj[n+1];

        for(auto e : times)
        {
            adj[e[0]].push_back({e[1], e[2]});
        }

        //Run Disjekstra

        vector<int> dis(n+1, INT32_MAX);

        bool vis[n+1];

        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;

        dis[k] = 0;

        vis[k] = 1;

        for(int i = 1; i <= n; ++i){
            pq.push({i, dis[i]});
            vis[i] = 0;
        }

        while(pq.size() > 0)
        {
            pair<int, int> curr = pq.top();
            pq.pop();
            if(vis[curr.first]) continue;
            curr.second = dis[curr.first];
            vis[curr.first] = 1;
            if(curr.second == INT32_MAX)
                return -1;

            for(auto ch : adj[curr.first])
            {
                if(vis[ch.first])
                    continue;


                if(dis[ch.first] > curr.second + ch.second)
                {
                    dis[ch.first] = curr.second + ch.second;
                    pq.push({ch.first, dis[ch.first]});
                }
            }

        }

        int mx = 0;

        for(int i = 1; i <= n; ++i)
        {
            if(dis[i] == INT32_MAX)
                return -1;
            mx = max(mx, dis[i]);
        }

        return mx;

    }
};