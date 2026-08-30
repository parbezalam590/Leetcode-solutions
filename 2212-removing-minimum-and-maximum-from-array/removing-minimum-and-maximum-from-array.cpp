class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        // how about sorting the nums to get the max and min ..and then find for min and max in the org array ..for min first if the array index is less than half of the size delete from front else from back ..similary for max 
         int n = nums.size();

    int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();
    int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();

    int bothFront = max(minIndex, maxIndex) + 1;

    int bothBack = n - min(minIndex, maxIndex);

    int minFrontMaxBack = minIndex + 1 + (n - maxIndex);

    int maxFrontMinBack = maxIndex + 1 + (n - minIndex);

    return min({
        bothFront,
        bothBack,
        minFrontMaxBack,
        maxFrontMinBack
    });
    }
};