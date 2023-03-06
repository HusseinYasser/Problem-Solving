class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        
        int ans = 0;
        
        if(rungs[0] > dist)
            ans += (rungs[0] )/dist  + ((rungs[0])%dist!=0 ? 1:0) - 1;
        
        for(int i = 0; i < rungs.size()-1; ++i)
        {
            if(rungs[i+1] - rungs[i] <= dist)
                continue;
            
            else
            {
                ans += (rungs[i+1] - rungs[i])/dist  + ((rungs[i+1] - rungs[i] )%dist==0 ? 0:1) - 1;
            }
            
        }
        
        return ans;
        
    }
};
