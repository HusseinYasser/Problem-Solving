#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        // i(i+1) /2 - 1 <= n
        int lo = 0, hi = n, ans = -1;
        while(lo <= hi)
        {
            int mid = (lo + hi)>>1;
            if(mid*1ll*(mid + 1ll)/2 <= n)
            {
                ans = mid;
                lo = mid+1;
            }
            else
                hi = mid - 1;
        }
        
        return ans;
        
    }
};
