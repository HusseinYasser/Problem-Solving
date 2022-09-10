#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Tortoise and hare algorithm
        int slow = 0, fast = 0;
        while(true)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow)
                break;
        }
        //Now we are in the intersection point inside the cycle
        slow = 0;
        while(slow != fast)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};

