class Solution {
public:
    
    long long fun(long long mid, vector<int> time)
    {
        long long trips = 0ll;
        for(auto nn : time)
            trips += mid/nn;
        
        return trips;
        
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long lo = 0, hi = 100000000000000ll, ans = -1;
        
        while(lo <= hi)
        {
            long long mid = (lo + hi)>>1;
            if(fun(mid, time) >= totalTrips)
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
