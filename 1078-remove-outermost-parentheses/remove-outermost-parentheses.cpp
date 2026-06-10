class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string res = "";
        for (char ch : s) {
            if (ch == '(') {
                if (cnt > 0)
                    res += ch;
                cnt++;
            } else {
                cnt--;
                 if (cnt > 0) res += ch;
            }
        }
        return res;
    }
};