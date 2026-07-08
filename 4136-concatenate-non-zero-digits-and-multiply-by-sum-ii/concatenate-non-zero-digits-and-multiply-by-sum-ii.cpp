class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> pos, digits;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digits.push_back(s[i] - '0');
            }
        }

        int m = digits.size();

        // prefix sum of digits
        vector<long long> prefSum(m + 1, 0);
        for (int i = 0; i < m; i++) {
            prefSum[i + 1] = prefSum[i] + digits[i];
        }

        // power of 10
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        // prefix concatenation value
        vector<long long> prefVal(m + 1, 0);
        for (int i = 0; i < m; i++) {
            prefVal[i + 1] = (prefVal[i] * 10 + digits[i]) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            auto it1 = lower_bound(pos.begin(), pos.end(), l);
            auto it2 = upper_bound(pos.begin(), pos.end(), r);

            if (it1 == it2) {
                ans.push_back(0);
                continue;
            }

            int L = it1 - pos.begin();
            int R = (it2 - pos.begin()) - 1;

            int len = R - L + 1;

            // get x using formula
            long long x = (prefVal[R + 1] - (prefVal[L] * pow10[len]) % MOD + MOD) % MOD;

            // sum of digits
            long long sum = prefSum[R + 1] - prefSum[L];

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};