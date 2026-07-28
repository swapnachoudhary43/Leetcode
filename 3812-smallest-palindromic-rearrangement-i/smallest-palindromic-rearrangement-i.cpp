class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        
        // Step 1: count frequency
        for (char c : s) {
            freq[c - 'a']++;
        }

        string half = "";
        string middle = "";

        // Step 2: build first half
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                middle = string(1, 'a' + i); // middle character
            }
            half += string(freq[i] / 2, 'a' + i);
        }

        // Step 3: build final answer
        string rev = half;
        reverse(rev.begin(), rev.end());

        return half + middle + rev;
    }
};