class Solution {
public:
    bool check(int zero, int one, int two) {
        if (one == 0)
            return false;

        one--;

        int mn = min(one, two);

        int len = 1 + 2 * mn + zero;

        one -= mn;
        two -= mn;

        if (one > 0) {
            len++;
            one--;
        }

        return (len % 2 == 1) && (one + two > 0);
    }
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        return check(cnt[0], cnt[1], cnt[2]) || check(cnt[0], cnt[2], cnt[1]);
    }
};