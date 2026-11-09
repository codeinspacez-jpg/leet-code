class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        long double current = x;
        if (N < 0) { current = 1 / current; N = -N; }
        
        long double ans = 1.0;
        for (; N > 0; N /= 2, current *= current) {
            if (N & 1) ans *= current;
        }
        return (double)ans;
    }
};