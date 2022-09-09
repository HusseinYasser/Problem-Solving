#include<iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(abs(n) == 1)
            return (n > 0)? x : 1/x;
        double k = myPow(x, n/2);
        double ans = k * k;
        if(abs(n)%2 == 1)
            ans *= (n > 0) ? x : 1/x;
        return ans;
    }
};