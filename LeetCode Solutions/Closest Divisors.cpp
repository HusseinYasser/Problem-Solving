#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    void solve(int x, vector<int>& ans, int& diff)
    {
        int div = sqrt(x);

        while(x % div != 0)
            div--;

        if(x/div - div < diff)
        {
            ans[0] = div;
            ans[1] = x / div;
            diff = x/div - div;
        }

    }

    vector<int> closestDivisors(int num) {

        //xy = num +1 or xy = num+2   abs(x - y) is min then if(num+1 || num+2 is)
        // we can try all possible divisiors of both num_1 and num+2 and then we pick the best 2 divisors

        vector<int> ans(2, -1);

        int diff = INT32_MAX;

        solve(num + 1, ans, diff);

        solve(num + 2, ans, diff);

        return ans;


    }
};