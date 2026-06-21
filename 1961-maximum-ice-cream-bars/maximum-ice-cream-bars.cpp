class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin() , costs.end());

        int cnt = 0;
        int sum = 0;
        for(int i = 0 ; i < costs.size() ; i++) {
            sum += costs[i];

            if(sum > coins) {
                break;
            }
            cnt++;
        }
        return cnt;
    }
};