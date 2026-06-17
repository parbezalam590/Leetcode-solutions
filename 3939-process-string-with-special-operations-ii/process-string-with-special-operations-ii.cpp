class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n + 1, 0);

        // Pass 1 : compute lengths
        for (int i = 0; i < n; i++) {

            if (islower(s[i])) {
                len[i + 1] = len[i] + 1;
            } else if (s[i] == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            } else if (s[i] == '#') {
                len[i + 1] = min((long long)1e15, len[i] * 2);
            } else { // %
                len[i + 1] = len[i];
            }
        }

        if (k >= len[n])
            return '.';

        // Pass 2 : work backwards
        for (int i = n - 1; i >= 0; i--) {

            if (islower(s[i])) {

                if (k == len[i])
                    return s[i];

            } else if (s[i] == '*') {

                // nothing to do
            } else if (s[i] == '#') {

                k %= len[i];
            } else { // %

                k = len[i] - 1 - k;
            }
        }

        return '.';
    }
};