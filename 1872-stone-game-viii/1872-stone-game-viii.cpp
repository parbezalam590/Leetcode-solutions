class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> dp(n, -1e9); 
        vector<int> preSum(n);
        
        preSum = stones;
        for (int i = 1; i < n; i++) {
            preSum[i] = preSum[i - 1] + stones[i];
        }
        
        int res = helper(preSum, 1, dp);
        return res;
    }
    int helper(const vector<int>& pre, int i, vector<int>& dp) {
        if (i == pre.size() - 1) return pre[pre.size() - 1];
        if (dp[i] != (int)-1e9) return dp[i];
        
        int take = pre[i] - helper(pre, i + 1, dp);
        int nottake = helper(pre, i + 1, dp);
        
        return dp[i] = max(take, nottake);
    }
    
};