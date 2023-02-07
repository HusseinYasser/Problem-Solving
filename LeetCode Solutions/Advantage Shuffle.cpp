#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans(nums1.size(), -1);

        sort(nums1.begin(), nums1.end());

        vector<pair<int,int>> vec;
        for(int i = 0; i < nums2.size(); ++i)
            vec.push_back({nums2[i], i});

        sort(vec.begin(), vec.end());

        map<int, int> left;

        int cmp = 0;

        for(int i = 0; i < nums1.size(); ++i)
        {
            if(nums1[i] > vec[cmp].first)
            {
                ans[vec[cmp++].second] = nums1[i];
            }
            else
            {
                //
                left[nums1[i]]++;
            }
        }
        for(int i = 0; i < ans.size(); ++i)
            if(ans[i] == -1)
            {
                ans[i] = left.begin()->first;
                left[left.begin()->first]--;
                if(!left[left.begin()->first])
                    left.erase(left.begin());
            }

        return ans;

    }
};