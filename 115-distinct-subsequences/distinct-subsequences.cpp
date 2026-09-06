class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {

        if (j == t.length()) {
            return 1;
        }

        if (i >= s.length()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int skip = solve(i + 1, j, s, t, dp);
        int take = 0;

        if (s[i] == t[j]) {
            take = solve(i + 1, j + 1, s, t, dp);
        }

        return dp[i][j] = take + skip;
    }
    int numDistinct(string s, string t) {

        int n = s.length();
        int m = t.length();

        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return solve(0, 0, s, t, dp);

        // vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
        vector<long long> prev(m + 1, 0);
        vector<long long> curr(m + 1, 0);
        prev[m] = 1;
        const int mod = 1e9 + 7;

        // for (int i = 0; i <= n; i++) {
        //     dp[i][m] = 1;
        // }

        for (int i = n - 1; i >= 0; i--) {

            curr[m] = 1;
            for (int j = m - 1; j >= 0; j--) {

                // long long skip = dp[i+1][j];
                // long long take = 0;

                long long skip = prev[j];
                long long take = 0;

                if (s[i] == t[j]) {
                    // take = dp[i+1][j+1];

                    take = prev[j + 1];
                }

                // dp[i][j] = (take + skip) % mod;

                curr[j] = (take + skip) % mod;
            }

            prev = curr;
        }

        // return  dp[0][0];

        return prev[0];
    }
};