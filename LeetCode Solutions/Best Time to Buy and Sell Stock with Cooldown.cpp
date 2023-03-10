class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp 
        vector<vector<int>> tab(prices.size()+2, vector<int>(2, 0));
        
        for(int i = prices.size() - 1; i > -1; --i)
        {
            tab[i][0] = max(tab[i][0], tab[i+1][0]);
            tab[i][0] = max(tab[i][0], -prices[i] + tab[i+1][1]);
            tab[i][1] = max(tab[i][1], tab[i+1][1]);
            tab[i][1] = max(tab[i][1], prices[i] + tab[i+2][0]);
            
        }
        return tab[0][0];
    }
};
