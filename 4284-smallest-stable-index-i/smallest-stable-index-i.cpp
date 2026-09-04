class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
    
        // we will basically iterate over each element of the array and then for that index we will first iterate from j = 0 to i and find the max element and then run loop from j = i to n -1 and find min from that range .. then we will subract and store the stable index then check if the stable index is less than or equal to k ..and return the smallest stable index 

         int n = nums.size();

        vector<int> right(n);
        right[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(right[i + 1], nums[i]);
        }

        int left = nums[0];

        for (int i = 0; i < n; i++) {
            left = max(left, nums[i]);

            if (left - right[i] <= k) {
                return i;
            }
        }

        return -1;
        }
};