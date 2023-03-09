class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.length()-1;
        bool check = 0;
        int ans = 2;
        while(i < j)
        {
            if(s[i] != s[j])
            {
                // we want to check twice now
                if(check){
                    ans--;
                    break;
                }
                check = 1;
                i++;
            }
            else
            {
                i++;
                j--;
            }
        }
        check = 0;
        i = 0, j = s.length()-1;
        while(i < j)
        {
            if(s[i] != s[j])
            {
                // we want to check twice now
                if(check){
                    ans--;
                    break;
                }
                check = 1;
                j--;
            }
            else
            {
                i++;
                j--;
            }
        }
        return ans? 1:0;
        
        
    }
};
