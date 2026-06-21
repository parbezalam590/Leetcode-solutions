class Solution {
public:
    const int MOD = 1e9 + 7;

    int power(long long  a, long long b) {
        if (b == 0)
            return 1;

        long long half = power(a, b / 2);
        long long ans = (half * half ) % MOD;

        if (b % 2 == 1) {
            ans = (ans * a ) % MOD;
        }

        return ans;
    }
    int countGoodNumbers(long long n) {
        long long odd = n / 2;
        long long even = (n + 1) / 2;

        long long result = (1LL * power(5, even) * power(4, odd)) % MOD;

        return result;
    }
};