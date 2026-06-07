class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> result;
        
        for (int mask = 0; mask < (1 << n); mask++) {
            string s = "";
            int cost = 0;
            bool valid = true;
            
            for (int i = 0; i < n; i++) {
                int bit = (mask >> (n - 1 - i)) & 1;
                s += (char)('0' + bit);
                if (bit == 1) cost += i;
                // consecutive 1s check
                if (i > 0 && s[i] == '1' && s[i-1] == '1') {
                    valid = false;
                    break;
                }
            }
            if (valid && cost <= k) result.push_back(s);
        }

        return result;
    }
};