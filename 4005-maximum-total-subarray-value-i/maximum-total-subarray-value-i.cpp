class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int gMax = INT_MIN , gMin = INT_MAX;

        for(int i = 0 ; i < nums.size() ; i++) {
            gMax = max(gMax , nums[i]);
            gMin = min(gMin , nums[i]);
        }
        long long ans = 1LL * (gMax - gMin) * k ;
        return ans;
    }
};