#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool check(int arr[], int arr2[])
    {
        for(int i = 0; i < 26; ++i)
            if(arr[i] != arr2[i])
                return 0;
        return 1;
    }

    bool checkInclusion(string s1, string s2) {

        int orig[26] = {};
        for(auto x : s1)
            orig[x - 'a']++;
        int curr[26] = {};
        int i = 0, j = 0;
        while(j < s2.length())
        {
            if(j - i >= s1.length())
            {
                bool h = check(curr, orig);
                if(h)
                    return 1;
                curr[s2[i++] - 'a']--;
            }
            curr[s2[j++] - 'a']++;
        }
        return check(curr, orig);


    }
};