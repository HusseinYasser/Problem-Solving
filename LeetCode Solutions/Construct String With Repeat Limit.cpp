#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {

        vector<int> freq(26, 0);

        for(auto ch : s)
            freq[ch - 'a']++;

        string ans = "";

        for(int i = 25; i > -1; --i)
        {
            int segments = freq[i] / repeatLimit;
            string seg = "";
            for(int j = 0; j < repeatLimit; ++j)
                seg.push_back('a' + i);
            string rem = "";
            for(int j = 0; j < freq[i]%repeatLimit; ++j)
                rem.push_back('a' + i);

            for(int k = 0; k < segments; ++k)
            {
                ans += seg;
                //find sep
                bool found = 0;
                for(int j = i-1; j > -1; --j)
                {
                    if(freq[j])
                    {
                        ans.push_back('a' + j);
                        freq[j]--;
                        found = 1;
                        break;
                    }
                }
                //what if i didn't find any seperator for me?
                if(!found)
                    return ans;
            }
            ans += rem;
            if(rem == "" && ans.size() && segments)
            {
                freq[ans.back() - 'a']++;
                ans.pop_back();
            }

        }

        return ans;

    }
};