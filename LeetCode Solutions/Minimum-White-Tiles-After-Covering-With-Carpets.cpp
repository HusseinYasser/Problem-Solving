#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int tab[1000+1][1000+1];

    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int cnt[(int)floor.size() + 1];
        cnt[(int)floor.size()] = 0;
        for(int i = floor.size()-1;i > -1; --i)
            cnt[i] = cnt[i+1] + ((floor[i] == '1')? 1:0);
        for(int i = 0 ; i <= floor.size(); ++i){
            tab[i][0] = cnt[i];
        }
        for(int i = 0;i <= numCarpets; ++i)
        {
            tab[floor.size()][i] = 0;
        }
        for(int carpet = 1; carpet <= numCarpets; ++carpet)
        {
            for(int tile = floor.size() - 1; tile > -1; --tile)
            {
                int x1 = tab[tile+1][carpet] + ((floor[tile] == '1')? 1:0);
                int x2 = tab[min(tile+carpetLen, (int)floor.size())][carpet-1];
                tab[tile][carpet] = min(x1,x2);
            }
        }
        return tab[0][numCarpets];

    }
};

