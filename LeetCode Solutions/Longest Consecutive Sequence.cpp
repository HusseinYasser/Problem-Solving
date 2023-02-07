#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int findPar(int a, unordered_map<int,int>& parents)
    {
        if(a == parents[a])
            return a;

        return parents[a] = findPar(parents[a], parents);
    }

    void merge(int a, int b, unordered_map<int,int>& parents, unordered_map<int,int>& sz)
    {
        a = findPar(a, parents), b = findPar(b, parents);

        if(a == b)
            return;

        if(sz[a] > sz[b]){
            parents[b] = a;
            sz[a] += sz[b];
        }
        else{
            parents[a] = b;
            sz[b] += sz[a];
        }

    }

    int longestConsecutive(vector<int>& nums) {
        //what about a DSU???!!!
        unordered_map<int, int> parents, sz;

        for(auto x : nums){
            parents[x] = x;
            sz[x] = 1;
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if(parents.find(nums[i]+1) != parents.end())
                merge(nums[i], nums[i]+1, parents, sz);

            if(parents.find(nums[i]-1) != parents.end())
                merge(nums[i], nums[i]-1, parents, sz);
        }

        int ans = 0;

        for(auto hh : sz)
            ans = max(ans, hh.second);

        return ans;

    }
};