#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {

        //as a master slave i have also to reply to the replica messages as well and send their replies too their corresponding servers too

        vector<int>adj[patience.size()];

        for(auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> dis(patience.size(), -1);
        dis[0] = 0;
        queue<int> q;
        q.push(0);
        while(q.size() > 0)
        {
            int curr = q.front();

            q.pop();

            for(auto ch : adj[curr])
            {
                if(dis[ch] == -1)
                {
                    dis[ch] = dis[curr] + 1;
                    q.push(ch);
                }
            }
        }

        int ans = 0;

        for(int i = 1; i < patience.size(); ++i)
        {
            int wayTime = 2*dis[i]; //time needed to send the message and get back in it
            int resendMessages = (wayTime-1)/patience[i]; //number of the resend messages this server will send back to the master thinking his message is ignored
            int lastTime = (resendMessages * patience[i]) + wayTime + 1;
            ans = max(ans, lastTime);

        }

        return ans;

    }
};
