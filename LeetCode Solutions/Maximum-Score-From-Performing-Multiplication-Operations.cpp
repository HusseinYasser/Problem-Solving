#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        long long tab[multipliers.size()+1][multipliers.size()+1];
        for(int i = 0 ; i <= multipliers.size() ; ++i)
            tab[multipliers.size()][i] = 0;
        for(int i = multipliers.size()-1; i > -1; --i)
        {
            for(int j = 0; j < i+1; ++j)
            {
                tab[i][j] = max(tab[i+1][j+1] + (nums[j]*multipliers[i]*1ll), tab[i+1][j] + (nums[nums.size() - 1 - (i - j)] * multipliers[i]*1ll));
            }
        }
        return tab[0][0];
    }
};
