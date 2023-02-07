#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<int> orig;

    Solution(vector<int>& nums) {
        orig = nums;
    }

    vector<int> reset() {
        return orig;
    }

    vector<int> shuffle() {
        vector<int> ans(orig.size(), 0);
        vector<int> tmp = orig;

        for(int i = 0; i < orig.size(); ++i)
        {
            int rnd = rand() % tmp.size();

            int tmpp = tmp[rnd];
            tmp[rnd] = tmp.back();
            tmp[tmp.size()-1] = tmpp;

            tmp.pop_back();

            ans[i] = tmpp;
        }

        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */