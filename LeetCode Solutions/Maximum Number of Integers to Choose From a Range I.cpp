#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        //the smallest numbers i can take not in banned and then we go
        //n is small 1e4 so we can go over the n and try to take from smallest to greatest
        unordered_set<int> st;
        for(auto x : banned)
            st.insert(x);

        int ans = 0;

        for(int i = 1; i <= n; ++i)
            if(st.find(i) == st.end())
            {
                if(maxSum < i)
                    break;
                ans++;
                maxSum -= i;
            }

        return ans;
    }
};