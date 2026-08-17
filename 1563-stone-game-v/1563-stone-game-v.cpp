class Solution {
public:

    int t[501][501];
    int solve(int l , int r, vector<int>& pSum) {
        if(l >= r) return 0;

        if(t[l][r] != -1){
            return t[l][r];
        }

        int score = 0;
        for(int mid = l ; mid <= r ; mid++) {

            int leftSum = pSum[mid] - (l-1 >= 0 ? pSum[l-1] : 0); 
            int rightSum = pSum[r] - pSum[mid];

            if(leftSum < rightSum) {
                score = max(score , leftSum + solve(l, mid, pSum));
            }
            else if(leftSum > rightSum) {
                score = max(score , rightSum + solve(mid+1 , r, pSum));
            }
            else {
                score =max({score ,leftSum + solve(l, mid, pSum) ,rightSum + solve(mid+1 , r, pSum)});
            }
        }
        return t[l][r] = score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        memset(t,-1,sizeof(t));
        int n = stoneValue.size();

        vector<int> pSum(n);
        pSum[0] = stoneValue[0];
        for(int i = 1 ; i < n ; i++) {
            pSum[i] = pSum[i-1] + stoneValue[i];
        }

        return solve(0, n-1, pSum);
    }
};