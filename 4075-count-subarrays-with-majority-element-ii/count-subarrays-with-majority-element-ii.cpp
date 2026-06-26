class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
   
               int n = nums.size();
        
        // Step 1: convert to +1 / -1
        vector<int> pref(n + 1, 0);
        for(int i = 0; i < n; i++) {
            int val = (nums[i] == target) ? 1 : -1;
            pref[i + 1] = pref[i] + val;
        }

        // Step 2: coordinate compression
        vector<int> temp = pref;
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        auto getIndex = [&](int x) {
            return lower_bound(temp.begin(), temp.end(), x) - temp.begin() + 1;
        };

        // Step 3: Fenwick Tree
        int m = temp.size();
        vector<int> BIT(m + 1, 0);

        auto update = [&](int i) {
            while(i <= m) {
                BIT[i]++;
                i += i & -i;
            }
        };

        auto query = [&](int i) {
            int sum = 0;
            while(i > 0) {
                sum += BIT[i];
                i -= i & -i;
            }
            return sum;
        };

        // Step 4: count
        long long ans = 0;
        for(int i = 0; i <= n; i++) {
            int idx = getIndex(pref[i]);
            ans += query(idx - 1); // count smaller prefix
            update(idx);
        }
        return ans;

    }
};