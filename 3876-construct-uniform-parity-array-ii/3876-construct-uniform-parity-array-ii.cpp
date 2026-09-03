class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = nums1[0];
        bool odd = false;

        for(int x : nums1 ){
            mn = min(mn , x);

            if(x % 2 == 1){
                odd = true;
            }
        }
        if(mn % 2 == 1){
            return true;
        }
        return !odd;
    }
};