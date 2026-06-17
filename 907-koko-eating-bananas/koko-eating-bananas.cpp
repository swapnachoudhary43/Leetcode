class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = left + (right - left) / 2;

            long long hours = 0;

            for (int pile : piles) {
                // ceil(pile / mid)
                hours += (pile + mid - 1) / mid;
            }

            if (hours <= h) {
                right = mid;  // try smaller speed
            } else {
                left = mid + 1;  // need more speed
            }
        }
        return left;
    }
};