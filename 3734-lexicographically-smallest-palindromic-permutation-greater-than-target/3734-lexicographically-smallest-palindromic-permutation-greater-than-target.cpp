class Solution {
public:
        string res = "";
    char odd = 0;
    int count_odd = 0;

    bool solve(int i, int half, string& target,
               vector<int>& count, string& temp, bool greater) {
        if (i == half) {
            if (greater) {
                string rev = temp;
                reverse(rev.begin(), rev.end());
                res = temp;
                if (count_odd)
                    res += odd;
                res += rev;
                return true;
            }
            string rev = temp;
            reverse(rev.begin(), rev.end());
            string candidate = temp;
            if (count_odd)
                candidate += odd;
            candidate += rev;
            if (candidate > target) {
                res = candidate;
                return true;
            }
            return false;
        }

        for (char c = 'a'; c <= 'z'; c++) {

            if (count[c - 'a'] < 2)
                continue;

            if (!greater && c < target[i])
                continue;

            bool nGreater = greater || (c > target[i]);

            count[c - 'a'] -= 2;
            temp.push_back(c);

            if (solve(i + 1, half, target,
                      count, temp, nGreater)) {
                return true;
            }

            temp.pop_back();
            count[c - 'a'] += 2;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        vector<int> count(26, 0);

        for (char c : s)
            count[c - 'a']++;

        count_odd = 0;

        for (int i = 0; i < 26; i++) {
            if (count[i] % 2) {
                count_odd++;
                odd = char('a' + i);
                count[i]--;
            }
        }

        if (count_odd > 1)
            return "";

        int half = n / 2;

        string temp = "";

        solve(0, half, target, count, temp, false);

        return res;
         
    }
};