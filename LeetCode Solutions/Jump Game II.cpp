#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& arr) {

        //Greedy by trying always to take the highest jump that will take me to the furthest point i can reach this will end in one of two ways either a reach and we guarantee that it will be minimum because iam always jumping to the highest point at every jump either it will end to nothing i can never reach from start to end

        int fuel = arr[0], start = 0, ans = 0;

        for(int i = 1; i < arr.size(); ++i)
        {
            int curr = 0, idx = -1;
            while(i < arr.size() && start + fuel >= i)
            {
                if(arr[i] + i > curr)
                {
                    curr = arr[i] + i;
                    idx = i;
                }
                i++;
            }

            if(idx == -1)
                return 0;

            i--;
            ans++;
            fuel = arr[idx];
            start = idx;

        }

        return ans;

    }
};