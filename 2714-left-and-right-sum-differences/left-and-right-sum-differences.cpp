class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
         int total = 0;

    for(int x : nums)
        total += x;

    int leftSum = 0;

    vector<int> ans;

    for(int i=0;i<nums.size();i++){

        int rightSum = total - leftSum - nums[i];

        ans.push_back(abs(leftSum - rightSum));

        leftSum += nums[i];
    }

    return ans;
    }
};