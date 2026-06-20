class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;

        if (nn == 0)
            return 1.0;

        if (nn < 0)
            nn = -nn;

        double half = myPow(x, nn / 2);
        ans = half * half;

        if (nn % 2 == 1) {
            ans *= x;
        }

        if (n < 0) {
            ans = 1.0 / ans;
        }
        return ans;
    }
};