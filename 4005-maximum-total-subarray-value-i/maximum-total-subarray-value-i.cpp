class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int min = nums[0], max = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < min) min = nums[i];
            if(nums[i] > max) max = nums[i];
        }
        
        long long diff = max - min;
        long long ans = 0;
        
        for(int i = 0; i < k; i++) {
            ans += diff;
        }
        
        return ans;
    }
};