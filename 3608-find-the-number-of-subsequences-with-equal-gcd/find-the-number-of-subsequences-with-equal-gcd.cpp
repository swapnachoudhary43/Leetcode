class Solution {
public:
    static const int MOD = 1e9+7;

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int subsequencePairCount(vector<int>& nums) {
        unordered_map<int, unordered_map<int, int>> dp;
        dp[0][0] = 1;

        for (int x : nums) {
            auto newdp = dp;

            for (auto &p1 : dp) {
                int g1 = p1.first;
                for (auto &p2 : p1.second) {
                    int g2 = p2.first;
                    int val = p2.second;

                    // put in seq1
                    int ng1 = gcd(g1, x);
                    newdp[ng1][g2] = (newdp[ng1][g2] + val) % MOD;

                    // put in seq2
                    int ng2 = gcd(g2, x);
                    newdp[g1][ng2] = (newdp[g1][ng2] + val) % MOD;
                }
            }

            dp.swap(newdp);
        }

        long long ans = 0;

        for (auto &p1 : dp) {
            int g1 = p1.first;
            if (g1 == 0) continue;

            if (p1.second.count(g1)) {
                ans = (ans + p1.second[g1]) % MOD;
            }
        }

        return ans;
    }
};