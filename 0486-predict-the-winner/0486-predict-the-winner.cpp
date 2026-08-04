class Solution {
public:

    //function that calculates the diff between p1 and p2
    int solve(int i , int j , vector<int>& nums) {

        if (i > j ) {
            return 0;
        }

        if(i == j ) return nums[i];

        int take_i = nums[i] - solve(i+1 ,j , nums);
        int take_j = nums[j] - solve(i ,j-1,nums);

        return max(take_i , take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        return solve(0 , n- 1 , nums) >= 0; // if the diff >= 0 return true
        
    }
};