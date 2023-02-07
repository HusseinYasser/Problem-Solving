#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int totalFruit(vector<int>& arr) {

        unordered_map <int, int> mp;

        int i = 0, j = 0, ans = 1;
        while(j < arr.size())
        {
            mp[arr[j]]++;
            if(mp.size() > 2)
            {
                ans = max(ans, j - i);
                mp[arr[i++]]--;
                if(!mp[arr[i-1]])
                    mp.erase(arr[i-1]);
            }
            j++;
        }
        if(mp.size() <= 2)
            ans = max(ans, j - i);

        return ans;
    }
};