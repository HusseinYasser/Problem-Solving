class Solution {
public:
    
    int run(string& tiles, vector<bool>&vis, string& soFar, unordered_set<string>& seen)
    {
        int ans = 0;
        for(int j = 0; j < tiles.size(); ++j)
        {
            if(!vis[j])
            {
                vis[j] = 1;
                soFar.push_back(tiles[j]);
                if(seen.find(soFar) == seen.end())
                    ans += 1;
                seen.insert(soFar);
                ans += run(tiles, vis, soFar, seen);
                soFar.pop_back();
                vis[j] = 0;
            }
        }
        return ans;
    }
    
    int numTilePossibilities(string tiles) {
        // trying all possible Permutations for all sizes
        unordered_set<string> st;
        vector<bool>vis(tiles.size(), 0);
        string soFar = "";
        return run(tiles, vis, soFar, st);
        
        
    }
};
