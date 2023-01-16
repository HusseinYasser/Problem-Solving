#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> ans;

        bool inserted = 0;

        for(int i = 0; i < intervals.size(); ++i)
        {
            vector<int> toBeInserted;
            if(newInterval[0] <= intervals[i][0] && !inserted)
            {
                toBeInserted = newInterval;
                inserted = 1;
                i--;
            }
            else
                toBeInserted = intervals[i];

            if(ans.size() == 0)
                ans.push_back(toBeInserted);
            else
            {
                if(ans.back()[1] >= toBeInserted[0])
                    ans.back()[1] = max(ans.back()[1], toBeInserted[1]);
                else
                    ans.push_back(toBeInserted);
            }


        }

        if(!inserted)
        {
            if(ans.size() == 0)
                ans.push_back(newInterval);
            else
            {
                if(ans.back()[1] >= newInterval[0])
                    ans.back()[1] = max(ans.back()[1], newInterval[1]);
                else
                    ans.push_back(newInterval);
            }
        }

        return ans;

    }
};