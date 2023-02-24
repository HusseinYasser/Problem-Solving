class Compare
{
    public:
    
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        priority_queue<int, vector<int>, Compare> pqMin;
        priority_queue<int> pqMax;
        
        int ans = INT32_MAX;
        
        int mn = -1, mx = -1;
        
        for(auto x : nums)
            pqMin.push(x);
        
        while(pqMin.size() && mn == -1)
        {
            if(pqMin.top()%2 == 0)
            {
                mn = pqMin.top();
                //pqMin.pop();
                break;
            }
            int x = pqMin.top();
            pqMin.pop();
            pqMin.push(2 * x);
        }
        
        while(pqMin.size())
        {
            pqMax.push(pqMin.top());
            pqMin.pop();
        }
        
        while(pqMax.size())
        {
            ans = min(ans, pqMax.top() - mn);
            //cout<<pqMax.top()<<" "<<mn<<endl;
            int x = pqMax.top();
            pqMax.pop();
            if(x%2 == 0)
            {
                mn = min(mn, x / 2);
                pqMax.push(x/ 2);
            }
            else
                break;
        }
        
        return ans;
        
    }
};
