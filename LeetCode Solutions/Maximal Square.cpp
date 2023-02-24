#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int getSum(int i1, int j1, int i2, int j2, vector<vector<int>>& arr)
    {
        int remove1 = (j1 > 0)? arr[i2][j1-1] : 0;
        int remove2 = (i1 > 0)? arr[i1-1][j2] : 0;
        int remove3 = (i1 > 0 && j1 > 0)? arr[i1-1][j1-1] : 0;
        return arr[i2][j2] - remove1 - remove2 + remove3;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        //Prefox sum over the grid and then we try all possible lengths in that case and get the best area

        vector<vector<int>> arr(matrix.size(), vector<int>(matrix[0].size(), 0));

        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < matrix[i].size(); ++j)
                arr[i][j] = matrix[i][j] - '0';
        }

        for(int i = 0; i < arr.size(); ++i)
        {
            for(int j = 0; j < arr[i].size(); ++j)
            {
                if(j > 0 )
                    arr[i][j] += arr[i][j-1];
            }

            for(int j = 0; j < arr[i].size(); ++j)
                if(i > 0)
                    arr[i][j] += arr[i-1][j];
        }

        int ans = 0;

        for(int len = 0; len <= max(matrix.size(), matrix[0].size()); ++len)
        {
            for(int i = 0; i < matrix.size(); ++i)
            {
                for(int j = 0; j < matrix[i].size(); ++j)
                {
                    if(i + len < matrix.size() && j + len < matrix[i].size())
                    {
                        int s = getSum(i, j, i+len, j+len, arr);
                        if(s == (len+1)*(len+1))
                            ans = (len+1)*(len+1);
                    }
                }
            }
        }

        return ans;



    }
};