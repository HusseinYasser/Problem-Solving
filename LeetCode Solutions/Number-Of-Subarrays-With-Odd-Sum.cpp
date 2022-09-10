#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int M = 1000000000+7;

    int numOfSubarrays(vector<int>& arr) {

        vector<int>prefixSum(arr.size(),0);
        prefixSum[0] = arr[0];
        for(int i = 1; i < arr.size(); ++i)
            prefixSum[i] += prefixSum[i-1]+arr[i];
        int ans = 0, odds = 0, evens = 0;

        for(int i = arr.size()-1;i > -1; --i)
        {
            if(prefixSum[i]%2 ==0)
                evens++;
            else
                odds++;
            int pastSum = (i > 0)? prefixSum[i-1]:0;
            if(pastSum%2 == 0)
                ans += odds;
            else
                ans += evens;
            ans %= M;
            odds %= M;
            evens %= M;
        }
        return ans;

    }
};