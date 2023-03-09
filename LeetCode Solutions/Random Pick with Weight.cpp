class Solution {
public:
    
    vector<int> prefix;
    
    Solution(vector<int>& w) {
        prefix.clear();
        prefix.push_back(w[0]);
        for(int i = 1; i < w.size(); ++i)
            prefix.push_back(w[i] + prefix.back());
        
    }
    
    int pickIndex() {
        int rnd = rand()%(prefix.back());
        int actualIndex = upper_bound(prefix.begin(), prefix.end(), rnd) - prefix.begin();
        return actualIndex;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
