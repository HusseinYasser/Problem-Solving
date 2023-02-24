#include<bits/stdc++.h

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {

        vector<int>dig;

        while(num > 0)
        {
            dig.push_back(num%10);
            num/=10;
        }

        for(int i = dig.size()-1; i > -1; --i)
        {
            int mx = 0, idx = -1;
            for(int j = 0; j <= i; ++j)
            {
                if(dig[j] > mx)
                {
                    idx = j;
                    mx = dig[j];
                }
            }
            if(idx == -1 || mx <= dig[i])
                continue;
            int tmp = dig[i];
            dig[i] = dig[idx];
            dig[idx] = tmp;
            break;
        }

        int ans = 0;
        for(int i = dig.size()-1; i > -1; --i)
        {
            ans *= 10;
            ans += dig[i];
        }

        return ans;
    }
};