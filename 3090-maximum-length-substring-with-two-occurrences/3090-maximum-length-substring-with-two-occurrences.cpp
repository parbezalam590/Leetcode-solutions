class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        unordered_map<int,int> mpp;
        int ans = 0;

        int left = 0;
        for(int right = 0 ; right < s.size() ; right++) {
            mpp[s[right]]++;

            while(mpp[s[right]] > 2) {
                mpp[s[left]]--;
                left++;
            }

            ans = max(ans , right - left +1);
        }
        return ans;
    }
};