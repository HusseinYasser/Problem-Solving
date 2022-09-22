#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<pair<int,int>>dq;
        vector<int>ans;
        for(int i = 0; i < arr.size(); ++i)
        {
            //add the new current element
            while(dq.size() > 0 && arr[i] > dq.back().first)
            {
                dq.pop_back();
            }
            dq.push_back({arr[i], i});
            //Get the Max elemnt
            if(i >= k-1)
            {
                while(dq.size() > 0 && i - dq.front().second >= k)
                    dq.pop_front();
                ans.push_back(dq.front().first);
            }
        }
        return ans;
    }
};
