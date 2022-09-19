#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] - 1ll >= 0 && nums[i] - 1ll < nums.size())
            {
                if(nums[i] - 1ll <= i && nums[i] != nums[nums[i]-1]){
                    long long tmp = nums[nums[i]-1];
                    nums[nums[i] - 1ll] = nums[i];
                    nums[i] = tmp;
                    i--;
                }
            }
        }
        for(int i = 0 ; i < nums.size(); ++i)
        {
            if(i != nums[i] - 1ll)
                return i+1ll;
        }
        return nums.size()+1ll;
    }
};

