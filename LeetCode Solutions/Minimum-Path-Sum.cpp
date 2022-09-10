#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int inf = 100000000;

    int minPathSum(vector<vector<int>>& grid) {
        int tab[grid.size()][grid[0].size()];
        tab[grid.size()-1][grid[0].size()-1] = grid[grid.size()-1][grid[0].size()-1];
        for(int i = grid.size()-1; i > -1; --i)
        {
            for(int j = grid[0].size()-1; j > -1; --j)
            {
                if(i == grid.size()-1 && j == grid[0].size()-1)
                    continue; //don't change the base case
                tab[i][j] = grid[i][j] + min((i < grid.size()-1) ? tab[i+1][j]:inf , (j<grid[0].size()-1) ? tab[i][j+1] : inf);
            }
        }
        return tab[0][0];

    }
};

