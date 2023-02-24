#include<bits/stdc++.h>

using namespace std;

class Solution {
public:


    bool fun(int mid, vector<int>& weights, int days)
    {
        int currWeight = 0, takenDays = 0;

        for(int i = 0; i < weights.size(); ++i)
        {
            if(currWeight + weights[i] <= mid)
            {
                currWeight += weights[i];
            }
            else
            {
                currWeight = weights[i];
                if(currWeight > mid)
                    return 0;
                takenDays++;
            }
        }

        if(currWeight)
            takenDays++;

        return takenDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        //Binary Search over the size of the package

        int lo = 0, hi = 500*5*10000;
        int ans = -1;
        while(lo <= hi)
        {
            int mid = (lo + hi)>>1;
            if(fun(mid, weights, days))
            {
                hi = mid - 1;
                ans = mid;
            }
            else
                lo = mid + 1;
        }

        return ans;

    }
};