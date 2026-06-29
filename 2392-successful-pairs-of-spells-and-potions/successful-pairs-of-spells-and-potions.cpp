class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
       int n = spells.size();
    int m = potions.size();
    sort(potions.begin(), potions.end());
    vector<int> pairs(n);
    
    for(int i = 0; i < n; i++) {
        long long min_potion = ceil((double)success / spells[i]);
        int low = 0, high = m - 1;
        int idx = m; // default: no valid potion found
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(potions[mid] >= min_potion) {
                idx = mid;
                high = mid - 1; 
            } else {
                low = mid +1; 
            }
        }
        pairs[i] = m- idx;  
    }
    return pairs;

    }
};