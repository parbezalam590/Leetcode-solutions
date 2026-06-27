class Solution {
public:
    void recurse(vector<vector<int>>& ans, vector<int>& sub, int index,
                 vector<int>& candidates, int target, int sum) {

        if (sum > target)
            return;

        if (sum == target) {
                ans.push_back(sub);
                return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            sub.push_back(candidates[i]);
            sum += candidates[i];

            recurse(ans, sub, i + 1, candidates, target, sum);
            sub.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sub;
        int sum = 0;

        sort(candidates.begin(), candidates.end());
        recurse(ans, sub, 0, candidates, target, sum);

        return ans;
    }
};