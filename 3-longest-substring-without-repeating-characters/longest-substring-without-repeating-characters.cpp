class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        for(int i = 0; i<256 ; i++) hash[i] =-1;

        int l=0, r=0, maxlen=0;
        int n = s.size();

        while(r<n){
            if(hash[s[r]]!=-1 && hash[s[r]]>=l){
                    l = hash[s[r]] + 1;
                }
            hash[s[r]] = r;
            maxlen =max(maxlen, r-l+1);
            r++;
        }
        return maxlen;  
    }
};