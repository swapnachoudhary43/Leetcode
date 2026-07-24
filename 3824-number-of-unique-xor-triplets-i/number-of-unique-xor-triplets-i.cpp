class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
       int n = nums.size();

        // case 1
        if (n <= 2) {
            unordered_set<int> st(nums.begin(), nums.end());
            return st.size();
        }

        // case 2
        int mx = *max_element(nums.begin(), nums.end());

        int k = 0;
        while ((1 << k) <= mx) k++;

        return (1 << k);
    }
};