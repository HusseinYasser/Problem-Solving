#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArrays(string s, int k) {

        vector<long long> tab(s.length()+1, 0);

        tab[s.length()] = 1ll;

        int M = 1000000000+7;

        for(int i = s.length()-1; i > -1; --i)
        {
            //check for if the number can be

            if(s[i] == '0')
                continue;

            long long tmp = 0ll;
            for(int j = 0; j < 10; ++j)
            {
                if(i + j >= s.length())
                    break;

                tmp*=10ll;
                tmp += (s[i+j] - 48);
                if(tmp <= k && tmp >= 1)
                    tab[i] = ((tab[i]%M) + (tab[i + j + 1]%M))%M;
            }
        }

        return tab[0];

    }
};