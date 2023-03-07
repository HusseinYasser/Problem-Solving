class Solution {
public:
    
    int find(int i, int n, int sum, vector<int>& suffix, int x)
    {
        if(sum == x)
            return n;
        int lo = i+1, hi = n-1, found = 0;
        while(lo <= hi)
        {
            int mid = (lo + hi)>>1;
            if((suffix[mid] + sum) == x)
            {
                return mid;
            }
            else if(suffix[mid] + sum < x)
                hi = mid - 1;
            else
                lo = mid+1;
        }
        return -10000000;
    }
    
    int minOperations(vector<int>& nums, int x) {
        
        //we are trying to find subarray from the left and subarray from the right and they will be our answer 
        int n = nums.size();
        vector<int> suffix(n, 0);
        suffix[n-1] = nums[n - 1];
        for(int i = n-2; i > -1; --i)
            suffix[i] += suffix[i + 1] + nums[i];
        int sum = 0;
        int ans = INT32_MAX;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            int found = find(i, n, sum, suffix, x);
            ans = min(ans, i + 1 + n - found);
        }
        ans = min(ans, n - find(-1, n, 0, suffix, x));
        
        if(ans > nums.size())
            ans = -1;
        
        
        return ans;
        
    }
};
