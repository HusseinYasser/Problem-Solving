#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {

        sort(cuts.begin(), cuts.end());

        vector<vector<int>> tab(cuts.size(), vector<int>(cuts.size(), INT32_MAX));

        for(int i = 0; i < cuts.size(); ++i)
            for(int j = 0; j < i; ++j)
                tab[i][j] = 0;

        for(int i = cuts.size() -1; i > -1; --i)
        {
            for(int j = i; j < cuts.size(); ++j)
            {
                int leftCut = (i > 0)? cuts[i-1]:0;
                int rightCut = (j < cuts.size()-1)? n - cuts[j+1]:0;
                int len = n - leftCut - rightCut;
                int ret = INT32_MAX;
                for(int k = i; k <= j; ++k)
                {
                    ret = min(ret, len + (k > 0? tab[i][k-1]:0) + (k < cuts.size()-1? tab[k+1][j]:0));
                }
                tab[i][j] = ret;
            }

        }
        return tab[0][cuts.size()-1];
    }
};

