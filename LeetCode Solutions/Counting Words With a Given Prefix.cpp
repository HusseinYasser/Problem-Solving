
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(auto word : words)
        {
            int i = 0;
            for(i = 0; i <min(pref.length(), word.length()); ++i)
                if(pref[i] != word[i])
                    break;
            ans += (i == pref.length())? 1:0;
                
        }
        return ans;
    }
};
