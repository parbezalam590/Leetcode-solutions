class Solution {
public:
    void helper(int idx, vector<vector<int>>& ans, vector<int>& nums,
                vector<int>& curr) {
        ans.push_back(curr);

            for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) {
                continue;
            }

            curr.push_back(nums[i]);

            helper(i + 1, ans, nums, curr);

            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        sort(nums.begin() , nums.end());
        helper(0, ans, nums, curr);
        return ans;
    }
};