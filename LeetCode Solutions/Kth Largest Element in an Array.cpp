class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //O(n) Solution
        vector<int> freq(2*10000 + 1, 0);
        for(auto h : nums)
        {
            freq[h + 10000]++;
        }
        for(int i = freq.size()-1; i > -1; --i)
        {
            if(freq[i] < k)
                k -= freq[i];
            else
                return i - 10000;
        }
        return 0;
        
    }
};
