class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int cntAns = 0;
        int size;
        for(int i = 0 ; i < n ; i++) {
            int cntT = 0;
            for(int j = i ; j < n ; j++) {
                if(nums[j] == target) {
                    cntT++;
                }
                size = j - i +1;

                if(cntT > size/2) {
                cntAns++;
            }
            }
            
            
        }
        return cntAns;
    }
};