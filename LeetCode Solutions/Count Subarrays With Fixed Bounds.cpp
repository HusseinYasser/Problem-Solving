class Solution {
public:
    
    
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        int mn = INT32_MAX, mx = INT32_MIN;
        int start = -1;
        long long ans = 0ll;
        //last appearence
        int mxIdx = -1, mnIdx = -1;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] < minK || nums[i] > maxK)
            {
                mn = INT32_MAX, mx = INT32_MIN;
                start = i;
            }
            else
            {
                if(nums[i] <= mn){
                    mn = nums[i];
                    mnIdx  = i;
                }
                if(nums[i] >= mx){
                    mx = nums[i];
                    mxIdx = i;
                }
                
                if(mn == minK && mx == maxK)
                    ans += (min(mxIdx, mnIdx) + 0ll - start);
            }
        }
        
        return ans;
        
    }
};
