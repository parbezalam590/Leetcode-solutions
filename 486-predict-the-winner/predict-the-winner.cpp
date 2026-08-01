class Solution {
public:

    int dp[21][21];

    int solve(vector<int>& nums, int left, int right) {

        // Only one element left
        if (left == right)
            return nums[left];

        if (dp[left][right] != -1)
            return dp[left][right];

        // Pick left
        int pickLeft = nums[left] - solve(nums, left + 1, right);

        // Pick right
        int pickRight = nums[right] - solve(nums, left, right - 1);

        return dp[left][right] = max(pickLeft, pickRight);
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));

        return solve(nums, 0, nums.size() - 1) >= 0;
    }
};