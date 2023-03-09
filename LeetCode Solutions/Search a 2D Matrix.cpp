class Solution {
public:
    
    bool bs(vector<int>& vec, int target)
    {
        int lo = 0, hi = vec.size()-1;
        while(lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if(vec[mid] == target)
                return 1;
            if(vec[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return 0;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int lo = 0, hi = matrix.size()-1;
        while(lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if(matrix[mid][0] <= target && matrix[mid][matrix[mid].size()-1] >= target)
            {
                return bs(matrix[mid], target);
            }
            else if(matrix[mid][0] > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        
        return 0;
        
    }
};
