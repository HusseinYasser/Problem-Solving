#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int>flipIndexes;
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            while(flipIndexes.size() > 0 && i >= flipIndexes.front())
                flipIndexes.pop();
            int change = 0;
            if(flipIndexes.size() > 0)
            {
                change = 1 - ((flipIndexes.size()-1)%2);
            }
            int curr = ((change)? change - nums[i]:nums[i]);
            if(curr == 0)
            {
                if(i <= nums.size() - k){
                    ans++;
                    flipIndexes.push(i + k);
                }
                else
                    return -1;
            }
        }
        return ans;
    }
};

