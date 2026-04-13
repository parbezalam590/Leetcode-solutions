class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans;
        int mini = INT_MAX;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] == target) {
                ans = abs(start - i);
                mini = min(mini , ans );
            }
        }
        return mini;
    }
};