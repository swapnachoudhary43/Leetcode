class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ind =0;
        int end = nums.size()-1;
        int mid =  (ind + end)/2;
        while(ind<= end){
            if(nums[mid]== target){
                return mid;
            }
            else if(nums[mid]<target ){
                ind = mid+1;

            }
            else{
                end = mid -1;
            }
            mid =  (ind + end)/2;
        }
        return -1;
        
    }
};