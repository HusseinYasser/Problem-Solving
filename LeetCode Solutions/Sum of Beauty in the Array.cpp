#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {

        int mx = nums[0];
        int mn[nums.size()];
        mn[nums.size()-1] = nums.back();
        for(int i = nums.size()-2; i  >-1; --i)
            mn[i] = min(mn[i+1], nums[i]);

        int ans = 0;
        for(int i = 1; i < nums.size() -1; ++i)
        {
            if(nums[i] > mx && nums[i] < mn[i+1])
                ans+=2;
            else if(nums[i] > nums[i-1] && nums[i] < nums[i+1])
                ans++;

            mx = max(mx, nums[i]);
        }

        return ans;

    }
};