#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {

        //You Go Left to Right and you meet a one you have one of two options bring down and continue
        //Or Decide that all the next will be One

        int ans = INT32_MAX;

        int freq[s.length()];

        int curr = 0;

        for(int i = 0; i < s.length(); ++i)
            freq[i] = 0;

        for(int i = s.length()-1; i > -1; --i)
        {
            if(i == s.length()-1)
                freq[i] = (s[i] == '0')?1:0;
            else
                freq[i] += freq[i+1] + ((s[i] == '0')?1:0);
        }

        for(int i = 0; i < s.length(); ++i)
        {
            if(s[i] == '1')
            {
                ans = min(curr + (i < s.length()-1? freq[i+1]:0), ans);
                curr++;
            }
        }

        ans = min(ans, curr);

        return ans;




    }
};