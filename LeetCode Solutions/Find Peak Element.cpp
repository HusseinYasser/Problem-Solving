class Solution {
public:
    
    
    
    int findPeakElement(vector<int>& arr) {
        int lo = 0, hi = arr.size()-1;
        while(lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if(mid == 0 || arr[mid] > arr[mid - 1])
            {
                if(mid == arr.size()-1 || arr[mid] > arr[mid + 1])
                    return mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
                
            
        }
        return -1;
        
    }
};
