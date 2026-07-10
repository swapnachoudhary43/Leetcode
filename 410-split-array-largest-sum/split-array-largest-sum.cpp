class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low <high){
            int mid = low +(high- low)/2;
            int load = 0,count=1;
            for(int sum : nums){
                if(load+sum > mid){
                    count++;
                    load =0;
                }
                load += sum;
            }
            if(count<= k) high =mid;
            else low = mid+1;
        }
        return low;
        
    }
};