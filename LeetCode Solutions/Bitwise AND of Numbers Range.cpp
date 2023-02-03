#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        //what are the number of 2 powers
        // what is the frequency of change of each bit
        int ans = 0;
        for(int i = 0; i < 32; ++i)
        {
            long long bit = ((1ll<<i)&left);
            int newLeft = (left&((1ll<<(i+1))-1));
            long long jumps = ((1ll<<(i+1))-newLeft);
            if(bit == 0)
                continue;
            if(left + jumps <= right)
                continue;
            ans += bit;
        }
        return ans;

    }
};