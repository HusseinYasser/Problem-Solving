#include<bits/stdc++.h>

using namespace std;


class Compare
{
public:

    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        if(p1.second == p2.second)
        {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //we can maintain to prioirty queues one indicating allData but sorted according to the capacity because smaller capacity higher chance to be elected
        //Second Priority queue can mainatin all elected (projects i can start) sorted by the price so we can take the best out of it and we can pour from the allData to the elected queue as long as we have capital than can take these projects
        //TC O(k + n) lg n   SC O(n)

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> allData;
        priority_queue<int> canBeTaken;

        for(int i = 0; i < profits.size(); ++i)
            allData.push({profits[i], capital[i]});

        for(int i = 0; i < k; ++i)
        {
            while(allData.size() && allData.top().second <= w)
            {
                canBeTaken.push(allData.top().first);
                allData.pop();
            }
            if(!canBeTaken.size())
                return w;
            w += canBeTaken.top();
            canBeTaken.pop();
        }

        return w;



    }
};