class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int end = 0;
        for(int i = s.length()-1; i > -1; --i)
            end += (s[i] == ')'? 1:0);
        
        string ans = ;
        int cnt = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            if(s[i] == '(')
            {
                if(end)
                {
                    ans.push_back(s[i]);
                    cnt++;
                    end--;
                }
            }
            else if(s[i] == ')')
            {
                if(cnt)
                {
                    cnt--;
                    ans.push_back(s[i]);
                }
                else
                    end--;
            }
            else
                ans.push_back(s[i]);
        }
        return ans;
        
    }
};
