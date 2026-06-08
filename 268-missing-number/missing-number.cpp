class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n = nums.size();
       int actualsum = 0;
       int expectedsum = n*(n+1)/2;
       for(int i =0;i<nums.size();i++){
        actualsum += nums[i];
       }
        return expectedsum - actualsum;  
    }
};