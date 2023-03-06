class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int last = 1;
        
        for(int i = 0; i < arr.size(); ++i)
        {
            if(arr[i] == last)
            {
                last++;
            }
            else
            {
                if(k == 1)
                {
                    return last;
                }
                k--;
                last++;
                i--;
            }
            
        }
        
        return last + k - 1 ;
        
        

        
    }
};
