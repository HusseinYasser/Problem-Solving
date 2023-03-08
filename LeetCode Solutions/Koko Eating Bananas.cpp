class Solution {
public:
    
    long long fun(int x, vector<int>& piles)
    {
        long long hours = 0ll;
        for(auto hh : piles)
        {
            hours += hh/x + (hh%x != 0 ? 1:0);
        }
        return hours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = 1000000000, ans = -1;
        while(lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if(fun(mid, piles) <= h)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        
        return ans;
        
    }
};
