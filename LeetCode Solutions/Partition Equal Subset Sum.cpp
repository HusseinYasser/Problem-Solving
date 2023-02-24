#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for(auto x : nums)
            sum += x;

        if(sum%2 == 1)
            return 0;


        vector<vector<int>> tab(nums.size()+1, vector<int>(sum/2 + 1, 0));

        for(int i = 0; i < nums.size(); ++i)
            tab[i][0] = 1;

        for(int curr = 1; curr <= sum/2; ++curr)
        {
            for(int i = nums.size()-1; i > -1; --i)
            {
                if(curr >= nums[i])
                    tab[i][curr] |= tab[i+1][curr - nums[i]];

                tab[i][curr] |= tab[i+1][curr];
            }
        }

        return tab[0][sum/2];

    }
};