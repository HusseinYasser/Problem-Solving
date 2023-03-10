class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp 
        vector<vector<int>> tab(prices.size()+2, vector<int>(1000+2, 0));
        
        for(int i = prices.size() - 1; i > -1; --i)
        {
            for(int j = 0; j <= 1001; ++j)
            {
                if(j == 1001)
                {
                    tab[i][j] = max(tab[i+1][prices[i]], tab[i][j]);
                }
                else if(prices[i] >= j)
                {
                    tab[i][j] = max(prices[i] - j + tab[i+2][1001], tab[i][j]);
                }
                tab[i][j] = max(tab[i][j], tab[i+1][j]);
            }
        }
        return tab[0][1001];
    }
};
