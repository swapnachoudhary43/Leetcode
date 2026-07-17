class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = *max_element(nums.begin(), nums.end());
        
        vector<long long> freq(maxVal + 1, 0);
        for (int x : nums) freq[x]++;
        
        vector<long long> cnt(maxVal + 1, 0);
        
        // Count how many numbers divisible by g
        for (int g = 1; g <= maxVal; g++) {
            for (int multiple = g; multiple <= maxVal; multiple += g) {
                cnt[g] += freq[multiple];
            }
        }
        
        vector<long long> pairs(maxVal + 1, 0);
        
        // Count pairs with gcd >= g
        for (int g = 1; g <= maxVal; g++) {
            long long c = cnt[g];
            pairs[g] = c * (c - 1) / 2;
        }
        
        // Inclusion-Exclusion to get exact gcd
        for (int g = maxVal; g >= 1; g--) {
            for (int multiple = 2 * g; multiple <= maxVal; multiple += g) {
                pairs[g] -= pairs[multiple];
            }
        }
        
        // Prefix sum
        vector<long long> prefix(maxVal + 1, 0);
        for (int g = 1; g <= maxVal; g++) {
            prefix[g] = prefix[g - 1] + pairs[g];
        }
        
        // Answer queries
        vector<int> ans;
        for (auto q : queries) {
            int l = 1, r = maxVal;
            while (l < r) {
                int mid = (l + r) / 2;
                if (prefix[mid] > q) r = mid;
                else l = mid + 1;
            }
            ans.push_back(l);
        }
        
        return ans;
    }
};