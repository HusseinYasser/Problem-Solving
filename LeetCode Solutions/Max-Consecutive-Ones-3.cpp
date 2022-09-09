#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, tmp = k, ans = 0;
        while(j < nums.size() && i < nums.size())
        {
            if(j < i)
                j = i;
            if(nums[j] == 1)
            {
                j++;
            }
            else
            {
                if(tmp == 0)
                {
                    ans = max(ans, j - i);
                    if(nums[i] == 0)
                        tmp++;
                    tmp = min(tmp, k);
                    i++;
                }
                else
                {
                    tmp--;
                    j++;
                }
            }
        }
        ans = max(ans, j - i);
        return ans;
    }
};

