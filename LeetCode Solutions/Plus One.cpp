class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        for(int i = 0; i < digits.size(); ++i)
        {
            digits[i]+=1;
            digits[i]%=10;
            if(digits[i])
            {
                reverse(digits.begin(), digits.end());
                return digits;
            }
        }
        digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
