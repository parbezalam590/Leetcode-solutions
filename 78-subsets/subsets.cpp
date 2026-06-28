class Solution {
public:

    void helper(int idx ,vector<vector<int>> &ans , vector<int>& nums , vector<int> &curr ) {

        if(idx == nums.size()) {
            ans.push_back(curr);
            return;
        }

        helper(idx + 1 , ans ,nums , curr );

        curr.push_back(nums[idx]);
        helper(idx + 1 , ans , nums , curr);

        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        helper(0,ans ,nums , curr);
        return ans;
    }
};