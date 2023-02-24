#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {

        int lo = 0, hi = arr.size()-1;

        while(lo <= hi)
        {
            int mid = (lo + hi)>>1;

            if(mid > 0 && mid < arr.size() && arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1])
                return arr[mid];

            if(mid%2 == 0)
            {
                if(mid > 0 && arr[mid] == arr[mid - 1])
                {
                    hi = mid - 1;
                }
                else if(mid > 0)
                {
                    lo = mid + 1;
                }
                else
                    break;
            }
            else
            {
                if(mid > 0 && arr[mid] == arr[mid - 1])
                    lo = mid + 1;
                else if(mid > 0)
                    hi = mid - 1;
                else
                    break;
            }
        }
        return arr[lo];
    }
};