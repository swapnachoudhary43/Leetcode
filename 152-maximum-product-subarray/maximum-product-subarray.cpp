class Solution {
public:
        int maxProduct(vector<int>& nums) {
    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];
    
    for(int i=1; i<nums.size(); i++) {
        int newMax = max({nums[i], 
                         maxProd*nums[i], 
                         minProd*nums[i]});
        int newMin = min({nums[i], 
                         maxProd*nums[i], 
                         minProd*nums[i]});
        maxProd = newMax;
        minProd = newMin;
        result = max(result, maxProd);
    }
    return result;

    }
};