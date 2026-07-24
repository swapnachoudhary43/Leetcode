class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> pairXor;
        int n = nums.size();

        // Step 1: all pair XORs (i <= j)
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }

        // Step 2: combine with third element
        unordered_set<int> result;
        for (int p : pairXor) {
            for (int x : nums) {
                result.insert(p ^ x);
            }
        }

        return result.size();
    }
};