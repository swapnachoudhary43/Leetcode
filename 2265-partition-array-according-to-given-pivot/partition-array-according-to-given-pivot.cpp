class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;

        for(int num : nums) {
            if(num < pivot) {
                less.push_back(num);
            }
            else if(num == pivot) {
                equal.push_back(num);
            }
            else {
                greater.push_back(num);
            }
        }

        // combine all
        vector<int> result;

        for(int x : less) result.push_back(x);
        for(int x : equal) result.push_back(x);
        for(int x : greater) result.push_back(x);

        return result;
    }
};