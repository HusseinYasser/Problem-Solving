class Solution {
public:
    
    void run(string& num, int n, int k, vector<int>& vec)
    {
        if(num.length() == n)
        {
            int nn = 0;
            for(int i = 0; i < num.length(); ++i)
                nn = (nn*10) + (num[i]-'0');
            vec.push_back(nn);
            return;
        }
        char lst = num.back();
        if((char)(lst + k) <= '9')
        {
            num.push_back((char)(lst + k));
            run(num, n, k, vec);
            num.pop_back();
        }
        if((char)(lst - k) >= '0' && k != 0)
        {
            num.push_back((char)(lst - k));
            run(num, n, k, vec);
            num.pop_back();
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int> ans;
        for(int i = 1; i < 10; ++i)
        {
            string s = to_string(i);
            run(s, n, k, ans);
        }
        
        return ans;
        
        
        
    }
};
