class Solution {
public:
    
    bool fun(string& a, string& b)
    {
        
        int j = 0;
        for(int i = 0; i < b.length() && j < a.length(); ++i)
            if(b[i] == a[j])
                j++;
        return j >= a.length();
    }
    
    int findLUSlength(vector<string>& strs) {
        //simple approach the answer is length of one of the strings if if it is not subsequence of all
        
        int ans = -1;
        
        for(int i = 0; i < strs.size(); ++i)
        {
            bool flag = 0;
            for(int j = 0; j < strs.size(); ++j)
            {
                if(i == j)
                    continue;
                flag |= fun(strs[i], strs[j]);
            }
                ans = max(ans, (int)strs[i].length());
        }
        
        return ans;
    }
};
