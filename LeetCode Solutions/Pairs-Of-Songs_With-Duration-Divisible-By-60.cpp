#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>mp;
        int ans = 0;
        for(auto t : time)
        {
            ans += mp[(60-(t%60))%60];
            mp[t%60]++;
        }
        return ans;
    }
};
