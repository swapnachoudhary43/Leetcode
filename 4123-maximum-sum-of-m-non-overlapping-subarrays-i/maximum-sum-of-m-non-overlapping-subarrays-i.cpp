class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        vector<long long> pre(n+1, 0);
        for (int i = 0; i < n; i++) pre[i+1] = pre[i] + nums[i];

        const long long NEG_INF = LLONG_MIN / 2;
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, NEG_INF));
        dp[0][0] = 0;

        long long ans = NEG_INF;

        for (int j = 1; j <= m; j++) {

            deque<int> dq;

            for (int i = 1; i <= n; i++) {

                int add_idx = i - l;
                if (add_idx >= 0 && dp[add_idx][j-1] != NEG_INF) {
                    long long val = dp[add_idx][j-1] - pre[add_idx];
                    while (!dq.empty() && 
                           dp[dq.back()][j-1] - pre[dq.back()] <= val)
                        dq.pop_back();
                    dq.push_back(add_idx);
                }

                while (!dq.empty() && dq.front() < i - r)
                    dq.pop_front();

                if (dp[i-1][j] != NEG_INF)
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);

                if (!dq.empty())
                    dp[i][j] = max(dp[i][j], pre[i] + dp[dq.front()][j-1] - pre[dq.front()]);

                dp[i][0] = 0;
            }

            for (int i = 1; i <= n; i++)
                if (dp[i][j] != NEG_INF) ans = max(ans, dp[i][j]);
        }

        return ans;
    }
};