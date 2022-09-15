#include<bits/stdc++.h>

using namespace std;

class Compare
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

class KthLargest {
public:

    priority_queue<int, vector<int>, Compare>pq;
    int k;

    KthLargest(int k, vector<int>& nums) {
        while(pq.size() > 0)
            pq.pop();
        this->k = k;
        for(auto number : nums){
            pq.push(number);
            if(pq.size() > k)
                pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if(pq.size() > k)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
