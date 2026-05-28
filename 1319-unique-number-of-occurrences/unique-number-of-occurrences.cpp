class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        int freq[2001] = {0};

        // Count frequency
        for(int i = 0; i < arr.size(); i++) {
            freq[arr[i] + 1000]++;
        }

        // Compare frequencies
        for(int i = 0; i < 2001; i++) {

            if(freq[i] == 0)
                continue;

            for(int j = i + 1; j < 2001; j++) {

                if(freq[i] == freq[j])
                    return false;
            }
        }

        return true;
    }
};