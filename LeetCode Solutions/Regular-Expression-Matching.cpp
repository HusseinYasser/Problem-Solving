#include <iostream>]

using namespace std;

class Solution {
public:

    bool isMatch(string s, string p) {

        bool tab[s.length()+1][p.length()+1];

        for(int i = 0; i < s.length()+1; ++i)
            for(int j =0 ; j < p.length()+1; ++j)
                tab[i][j] = 0;

        tab[s.length()][p.length()] = 1;

        for(int i = s.length() ; i > -1; --i)
        {
            for(int j = p.length() - 1 ; j > -1; --j)
            {
                tab[i][j] = 0;
                if(i == s.length())
                {
                    if(p[j] == '*' || (j < p.length()-1 && p[j+1] == '*'))
                        tab[i][j] = tab[i][j+1];
                    else
                        tab[i][j] = 0;
                }
                else
                {
                    if(p[j] == '.'){
                        if(j < p.length()-1 && p[j+1] == '*')
                            tab[i][j] = tab[i][j+1];
                        else
                            tab[i][j] = tab[i+1][j+1];
                    }
                    else if(p[j] == '*')
                    {
                        if(s[i] != p[j-1] && p[j-1] != '.')
                            tab[i][j] = tab[i][j+1];
                        else
                        {
                            tab[i][j] |= tab[i+1][j+1];
                            tab[i][j] |= tab[i+1][j];
                            tab[i][j] |= tab[i][j+1];
                        }
                    }
                    else
                    {
                        if(j < p.length()-1 && p[j+1] == '*')
                            tab[i][j] = tab[i][j+1];
                        else
                        {
                            if(s[i] != p[j])
                                tab[i][j] = 0;
                            else
                                tab[i][j] = tab[i+1][j+1];
                        }
                    }
                }
            }
        }
        return tab[0][0];
    }
};