class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
         int n = s.size();
        int freq[26] = {};

        for (char c : s)
            freq[c - 'a']++;

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            if (freq[x] > 0) {
                freq[x]--;
                continue;
            }

            for (int j = i; j >= 0; j--) {
                if (j < i)
                    freq[target[j] - 'a']++;

                int cur = target[j] - 'a';

                for (int c = cur + 1; c < 26; c++) {
                    if (freq[c] > 0) {
                        string ans = target.substr(0, j);
                        ans += char('a' + c);
                        freq[c]--;

                        for (int x = 0; x < 26; x++)
                            ans += string(freq[x], char('a' + x));

                        return ans;
                    }
                }
            }

            return "";
        }

        for (int j = n - 1; j >= 0; j--) {
            freq[target[j] - 'a']++;

            int cur = target[j] - 'a';

            for (int c = cur + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    string ans = target.substr(0, j);
                    ans += char('a' + c);
                    freq[c]--;

                    for (int x = 0; x < 26; x++)
                        ans += string(freq[x], char('a' + x));

                    return ans;
                }
            }
        }

        return "";
    }
};