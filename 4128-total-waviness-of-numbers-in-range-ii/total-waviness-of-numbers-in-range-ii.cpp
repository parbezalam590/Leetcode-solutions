class Solution {
public:
    struct Node {
        long long ways;
        long long wave;
    };

    string s;

    Node dp[20][2][2][11][11];
    bool vis[20][2][2][11][11];

    Node digitDP(int pos, int tight, int started, int prev1, int prev2) {

        if (pos == s.size())
            return {1, 0};

        if (vis[pos][tight][started][prev1][prev2])
            return dp[pos][tight][started][prev1][prev2];

        vis[pos][tight][started][prev1][prev2] = true;

        Node ans = {0, 0};

        int limit = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= limit; d++) {

            int ntight = tight && (d == limit);

            if (!started && d == 0) {

                Node nxt = digitDP(pos + 1, ntight, 0, 10, 10);

                ans.ways += nxt.ways;
                ans.wave += nxt.wave;

                continue;
            }

            int add = 0;

            /*
             prev2 prev1 d

             determine if prev1
             becomes peak/valley
            */

            if (prev1 != 10 && prev2 != 10) {

                if (prev1 > prev2 && prev1 > d)
                    add = 1;

                else if (prev1 < prev2 && prev1 < d)
                    add = 1;
            }

            int np1 = d;

            int np2 = (prev1 == 10) ? 10 : prev1;

            Node nxt = digitDP(pos + 1, ntight, 1, np1, np2);

            ans.ways += nxt.ways;

            ans.wave += nxt.wave + nxt.ways * add;
        }

        return dp[pos][tight][started][prev1][prev2] = ans;
    }

    long long solve(long long x) {

        if (x <= 0)
            return 0;

        s = to_string(x);

        memset(vis, 0, sizeof(vis));

        return digitDP(0, 1, 0, 10, 10).wave;
    }

    long long totalWaviness(long long num1, long long num2) {

        return solve(num2) - solve(num1 - 1);
    }
};