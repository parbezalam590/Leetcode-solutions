class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        auto solve = [&](vector<int>& firstStart, vector<int>& firstDur,
                         vector<int>& secondStart, vector<int>& secondDur) {
            int m = secondStart.size();

            vector<pair<int, int>> rides;
            for (int i = 0; i < m; i++)
                rides.push_back({secondStart[i], secondDur[i]});

            sort(rides.begin(), rides.end());

            vector<int> starts(m);
            vector<long long> prefMinDur(m), suffMinFinish(m);

            for (int i = 0; i < m; i++)
                starts[i] = rides[i].first;

            for (int i = 0; i < m; i++) {
                if (i == 0)
                    prefMinDur[i] = rides[i].second;
                else
                    prefMinDur[i] =
                        min(prefMinDur[i - 1], (long long)rides[i].second);
            }

            for (int i = m - 1; i >= 0; i--) {
                long long val = 1LL * rides[i].first + rides[i].second;
                if (i == m - 1)
                    suffMinFinish[i] = val;
                else
                    suffMinFinish[i] = min(suffMinFinish[i + 1], val);
            }

            long long ans = LLONG_MAX;

            for (int i = 0; i < firstStart.size(); i++) {

                long long finishFirst = 1LL * firstStart[i] + firstDur[i];

                int idx =
                    upper_bound(starts.begin(), starts.end(), finishFirst) -
                    starts.begin() - 1;

                long long cur = LLONG_MAX;

                // rides already available
                if (idx >= 0)
                    cur = min(cur, finishFirst + prefMinDur[idx]);

                // rides opening later
                if (idx + 1 < m)
                    cur = min(cur, suffMinFinish[idx + 1]);

                ans = min(ans, cur);
            }

            return ans;
        };

        long long landFirst =
            solve(landStartTime, landDuration, waterStartTime, waterDuration);

        long long waterFirst =
            solve(waterStartTime, waterDuration, landStartTime, landDuration);

        return (int)min(landFirst, waterFirst);
    }
};