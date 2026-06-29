class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;

        for (int i = 0; i < patterns.size(); i++) {

            string pat = patterns[i];
            int m = pat.size();
            int n = word.size();

            bool found = false;

            for (int j = 0; j <= n - m; j++) {

                bool match = true;

                for (int k = 0; k < m; k++) {

                    if (word[j + k] != pat[k]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    found = true;
                    break;
                }
            }

            if (found)
                cnt++;
        }

        return cnt;
    }
};