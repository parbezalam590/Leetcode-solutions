class Solution {
public:
    int maximumLengthSubstring(string s) {

        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_map<int, int> mpp;

            for (int j = i; j < s.size(); j++) {
                mpp[s[j]]++;
                if (mpp[s[j]] > 2)
                    break;

                ans = max(ans,j - i + 1);
            }
        }
        return ans;
    }
};