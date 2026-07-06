class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        while(low < high) {
            int mid = low + (high-low)/2;
            int days_needed = 1;
            int load = 0;

            for(int weight : weights) {
                if(load + weight > mid) {
                    days_needed++;
                    load = 0;
                }
                load += weight;
            }

            if(days_needed <= days) high = mid;  
            else low = mid+1;                     
        }
        return low;
    }
};