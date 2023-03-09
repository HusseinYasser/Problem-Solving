class Solution {
public:
    
    int dirX[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dirY[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    bool isvalid(int x, int y, int n)
    {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //bfs
        vector<vector<int>> dis(grid.size(), vector<int>(grid[0].size(), -1));
        queue<pair<int,int>> q;
        if(grid[0][0] == 0)
        {
            dis[0][0] = 1;
            q.push({0, 0});
        }
        while(q.size())
        {
            pair<int,int> curr = q.front();
            q.pop();
            for(int i = 0; i < 8; ++i)
            {
                int newX = dirX[i] + curr.first;
                int newY = dirY[i] + curr.second;
                    continue;
                dis[newX][newY] = dis[curr.first][curr.second] + 1;
                q.push({newX, newY});
            }
        }
        return  dis[grid.size()-1][grid.size()-1];
        
    }
};
