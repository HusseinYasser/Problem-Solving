#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int inf = nums.size()+1;

        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] < 1)
                nums[i] = inf;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(abs(nums[i]) - 1 < nums.size())
                nums[abs(nums[i]) - 1] = -1*abs(nums[abs(nums[i]) - 1]);
        }

        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] > 0)
                return i+1;

        return  inf;

    }
};