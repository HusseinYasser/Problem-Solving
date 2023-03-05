class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        //bfs traversal
        queue<int> q;
        q.push(0);
        vector<int> dis(arr.size(), -1);
        dis[0] = 0;
        map<int, vector<int>> mp;
        for(int i = 0; i < arr.size(); ++i)
            mp[arr[i]].push_back(i);
        
        while(q.size() > 0)
        {
            int i = q.front();
            
            q.pop();
            
            if(i == arr.size() - 1)
            {
                return dis[i];
            }
            
            if(i > 0 && dis[i - 1] == -1)
            {
                dis[i - 1] = dis[i] + 1;
                q.push(i - 1);
            }
            if(i < arr.size() - 1 && dis[i + 1] == -1)
            {
                dis[i + 1] = dis[i] + 1;
                q.push(i + 1);
            }
            //last thing here
            for(auto h : mp[arr[i]])
            {
                if(dis[h] == -1)
                {
                    dis[h] = dis[i] + 1;
                    q.push(h);
                }
            }
            mp[arr[i]].clear();
        }
        
        return -1;
        
    }
};
