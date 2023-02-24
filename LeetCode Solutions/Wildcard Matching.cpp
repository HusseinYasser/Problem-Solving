#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {

        vector<vector<bool>> tab(p.size()+1, vector<bool>(s.size()+1, 0));

        tab[p.length()][s.length()] = 1;

        for(int i = p.length(); i > -1; --i)
        {
            for(int j = s.length(); j > -1; --j)
            {
                if(i == p.length() && j == s.length())
                    continue;

                if(i < p.length() && p[i] == '?')
                {
                    tab[i][j] = j < s.length() ? tab[i+1][j+1]:0;
                }
                else if(i < p.length() && p[i] == '*')
                {
                    //Here Match Zero or more
                    tab[i][j] = tab[i+1][j] || (j < s.length()? tab[i][j+1] : 0);
                }
                else if(i < p.length() && j < s.length())
                {
                    if(p[i] != s[j])
                    {
                        tab[i][j] = 0;
                    }
                    else
                        tab[i][j] = tab[i+1][j+1];
                }

            }
        }

        return tab[0][0];

    }
};