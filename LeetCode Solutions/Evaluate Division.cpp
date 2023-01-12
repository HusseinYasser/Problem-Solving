#include <bits/stdc++.h>

using namespace std;


class Compare{
public:

    bool operator() (pair<string, double> p1, pair<string, double> p2)
    {
        return p1.second > p2.second;
    }
};

class Solution {
public:


    double sp(string src, string dst, map<string, vector<pair<string, double>>> mp)
    {

        if(mp.find(src) == mp.end() || mp.find(dst) == mp.end())
            return -1;

        map<string, double> distance;
        map<string, bool> vis;
        for(auto xx : mp){
            distance[xx.first] = 100000000;
            vis[xx.first] = 0;
        }

        distance[src] = 1;

        vis[src] = 1;

        priority_queue<pair<string, double>, vector<pair<string, double>>, Compare> pq;

        pq.push({src, 1});


        while(pq.size() > 0)
        {
            pair<string, double> curr = pq.top();
            pq.pop();

            for(auto ch : mp[curr.first])
            {
                if(vis[ch.first])
                    continue;

                if(distance[ch.first] > distance[curr.first] * ch.second)
                    distance[ch.first] = distance[curr.first] * ch.second;


                pq.push({ch.first, distance[ch.first]});
                vis[ch.first] = 1;
            }
        }
        if(vis[dst] == 0) return -1;
        return distance[dst];



    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        map<string, vector<pair<string, double>>> mp;

        for(int i = 0; i < equations.size(); ++i)
        {
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], (1+0.0)/values[i]});
        }

        vector<double> ans;

        for(auto q : queries)
        {
            double ret = sp(q[0], q[1], mp);
            ans.push_back(ret);
        }

        return ans;

    }
};