#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {

        //1000 * 1000 * k

        for(int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];

        vector<vector<int>> tab(nums.size()+1, vector<int>(k+1, 0));

        for(int i = 0; i < nums.size()-1; ++i)
        {
            tab[i][0] = INT32_MAX;
        }

        for(int i = 1; i <= k; ++i)
            tab[nums.size()-1][i] = INT32_MAX;

        for(int i = nums.size(); i > -1; --i)
        {
            for(int j = 1; j <= k; ++j)
            {
                int ans = INT32_MAX;

                for(int i2 = i+1; i2 < nums.size(); ++i2)
                {
                    ans = min(ans, max(nums[i2] - nums[i], tab[i2][j-1]));
                }
                tab[i][j] = ans;
            }
        }

        int ans = INT32_MAX;

        for(int i = 0; i < nums.size(); ++i)
            ans = min(ans, max(nums[i], tab[i][k-1]));

        return ans;

    }
};