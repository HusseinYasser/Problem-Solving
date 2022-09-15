#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        //dp problem with states i for s and j for t

        int tab[s.length()+1][t.length()+1];
        for(int i = 0; i <= s.length(); ++i)
            for(int j = 0 ; j <= t.length(); ++j)
                tab[i][j] = 0;

        for(int i = 0 ; i <= s.length(); ++i)
            tab[i][t.length()] = 1;

        for(int j = t.length()-1; j > -1; --j)
        {
            for(int i = s.length()-1; i > -1; --i)
            {
                long long ans = 0;
                if(s[i] == t[j])
                    ans += tab[i+1][j+1];
                ans += tab[i+1][j];
                tab[i][j] = ans;
            }
        }
        return tab[0][0];
    }
};

