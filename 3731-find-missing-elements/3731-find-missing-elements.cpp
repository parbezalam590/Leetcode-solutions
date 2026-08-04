class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        int mini = nums[0];
        int maxi = nums[0];
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
            }
            if (nums[i] < mini) {
                mini = nums[i];
            }
        }

        unordered_map<int, int> mpp;
        for (auto it : nums) {
            mpp[it]++;
        }

        for (int i = mini; i <= maxi; i++) {
            if (mpp[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};