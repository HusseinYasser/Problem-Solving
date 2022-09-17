#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        long long tab[word1.length()+1][word2.length()+1];
        tab[word1.length()][word2.length()] = 0ll;
        for(int i = 0; i < word1.length(); ++i)
            tab[i][word2.length()] = word1.length()-i+0ll;
        for(int i = 0; i < word2.length(); ++i)
            tab[word1.length()][i] = word2.length()-i;
        for(int j = word2.length()-1; j > -1; --j)
        {
            for(int i = word1.length()-1; i > -1; --i)
            {
                if(word1[i] == word2[j])
                    tab[i][j] = tab[i+1][j+1];
                else
                {
                    tab[i][j] = 1ll + min(tab[i][j+1], tab[i+1][j]);
                    tab[i][j] = min(tab[i][j], 1ll + tab[i+1][j+1]);
                }
            }
        }
        return tab[0][0];
    }
};
