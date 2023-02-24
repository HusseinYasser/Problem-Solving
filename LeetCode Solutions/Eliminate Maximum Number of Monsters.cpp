#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {

        //i lose when i have two monsters can reach at the same time or diff one in their time
        //rather tahn that i can kill them all
        //Ok what if it is the case then i will be able to kill all monsters before them in that case
        //So prepare the times and then sort them and count

        //greedy way better to always kill the nearer to the city then the farther this will allow you kill more because once you leave the near monster it can end you game early but if you kill him you won't lose anything regarding farther monsters and still have high chances for killing more

        vector<int> reachTimes(dist.size(), 0);

        for(int i = 0; i < dist.size(); ++i)
        {
            reachTimes[i] = (dist[i] / speed[i]) + (dist[i]%speed[i] != 0 ? 1:0);
        }

        sort(reachTimes.begin(), reachTimes.end());

        int ans = 0;

        for(int i = 0; i < reachTimes.size(); ++i)
        {
            if(reachTimes[i] < i+1) //someone reached the city while iam trying to kill another monsters
                return ans;

            ans++;
        }

        return ans;

    }
};