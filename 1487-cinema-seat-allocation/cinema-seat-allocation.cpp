class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, set<int>> mp;

        for (auto x : reservedSeats)
            mp[x[0]].insert(x[1]);

        int ans = (n - mp.size()) * 2;

        for (auto x : mp) {
            int row = x.first;
            auto seats = x.second;

            bool left = true;
            bool mid = true;
            bool right = true;

            for (int i = 2; i <= 5; i++)
                if (seats.count(i))
                    left = false;

            for (int i = 4; i <= 7; i++)
                if (seats.count(i))
                    mid = false;

            for (int i = 6; i <= 9; i++)
                if (seats.count(i))
                    right = false;

            if (left && right)
                ans += 2;
            else if (left || mid || right)
                ans += 1;
        }

        return ans;
    }
};