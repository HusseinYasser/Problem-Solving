class Solution {
public:
    int knightDialer(int n) {
        
        int m = 1000000000 + 7;
        
        vector<vector<long long>> tab(n+1, vector<long long>(10, 0ll));
        for(int i = 0; i < 10; ++i)
            tab[n][i] = 1ll;
        
        for(int i = n-1; i > -1; --i)
        {
            tab[i][0] = (tab[i][0]%m + tab[i+1][4]%m)%m;
            tab[i][0] = (tab[i][0]%m + tab[i+1][6]%m)%m;
            tab[i][7] = (tab[i][7]%m + tab[i+1][6]%m)%m;
            tab[i][7] = (tab[i][7]%m + tab[i+1][2]%m)%m;
            tab[i][9] = (tab[i][9]%m + tab[i+1][4]%m)%m;
            tab[i][9] = (tab[i][9]%m + tab[i+1][2]%m)%m;
            tab[i][4] = (tab[i][4]%m + tab[i+1][3]%m)%m;
            tab[i][4] = (tab[i][4]%m + tab[i+1][9]%m)%m;
            tab[i][4] = (tab[i][4]%m + tab[i+1][0]%m)%m;
            tab[i][6] = (tab[i][6]%m + tab[i+1][1]%m)%m;
            tab[i][6] = (tab[i][6]%m + tab[i+1][7]%m)%m;
            tab[i][6] = (tab[i][6]%m + tab[i+1][0]%m)%m;
            tab[i][3] = (tab[i][3]%m + tab[i+1][4]%m)%m;
            tab[i][3] = (tab[i][3]%m + tab[i+1][8]%m)%m;
            tab[i][1] = (tab[i][1]%m + tab[i+1][6]%m)%m;
            tab[i][1] = (tab[i][1]%m + tab[i+1][8]%m)%m;
            tab[i][2] = (tab[i][2]%m + tab[i+1][7]%m)%m;
            tab[i][2] = (tab[i][2]%m + tab[i+1][9]%m)%m;
            tab[i][8] = (tab[i][8]%m + tab[i+1][3]%m)%m;
            tab[i][8] = (tab[i][8]%m + tab[i+1][1]%m)%m;
        }
        
        long long ans = 0ll;
        for(int i = 0; i < 10; ++i)
        {
            ans = (ans%m + tab[1][i]%m)%m;
        }
        
        return ans;
        
        
    }
};
