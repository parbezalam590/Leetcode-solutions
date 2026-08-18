class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> count(51,0);

        for(int i = 0 ; i <= n-k ; i++) {
            unordered_set<int> visited;

            for(int j = i ; j < i+k ; j++) {
                visited.insert(nums[j]);
            }

            for(int x : visited) {
                count[x]++;
            }
        }

        for(int i = 50 ; i >= 0 ; i--) {
            if(count[i] == 1) {
                return i;
            }
        }
        return -1;

    }
};