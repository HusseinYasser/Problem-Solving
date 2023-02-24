#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        /*
        Always the answer is found when we try to make the element match one of the values of the array
        So it will always be the frequency of one of the values of the array and we want to know which value would be the best
        */

        //One of the Ways is to binary search on the largest sum you can get before the target you need

        sort(nums.begin(), nums.end());

        int ans = 1;

        vector<long long> prefix(nums.size(), 0);

        prefix[0] = nums[0];

        for(int i = 1; i < nums.size(); ++i)
            prefix[i] += nums[i] + prefix[i - 1];

        for(int i = 1; i < prefix.size(); ++i)
        {
            int target = prefix[i] - prefix[i - 1];

            int lo = 0, hi = i-1;
            while(lo <= hi)
            {
                int mid = (lo + hi)>>1;
                long long sumOfElementsBeTaken = prefix[i-1] - (mid > 0 ? prefix[mid-1]:0);
                int numberOfTaken = i - mid;
                if(numberOfTaken*1ll*target - sumOfElementsBeTaken <= k) // can be done
                {
                    ans = max(ans, numberOfTaken + 1);
                    hi = mid - 1;
                }
                else
                    lo = mid + 1;
            }
        }

        return ans;



    }
};