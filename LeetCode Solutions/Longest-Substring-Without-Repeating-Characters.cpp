#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, ans = 0;
        unordered_set<char>seen;
        while(j < s.length() && i < s.length())
        {
            if(seen.find(s[j]) == seen.end())
                seen.insert(s[j++]);
            else
            {
                //Now we have a repeated character
                ans = max(ans, j - i);
                seen.erase(s[i++]);
            }
        }
        ans = max(ans, j - i);
        return ans;

    }
};

