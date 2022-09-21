#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0, ans = 0;
        for(auto ch : s)
        {
            if(ch == '['){
                cnt++;
            }
            else
            {
                cnt--;
                if(cnt < 0)
                {
                    ans++;
                    cnt = 1;
                }
            }
        }
        return ans;
    }
};
