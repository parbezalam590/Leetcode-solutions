class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> ans(gain.size() + 1 , 0); // mkaing ans from gain which is of +1 size
        int maxi = 0; // min is 0 ..as the biker starts from 0 
        for(int i = 0 ; i < gain.size() ; i++) {
            ans[i+1] = ans[i] + gain[i];  

            maxi = max(maxi , ans[i + 1]);
        }
        return maxi;
    }
};