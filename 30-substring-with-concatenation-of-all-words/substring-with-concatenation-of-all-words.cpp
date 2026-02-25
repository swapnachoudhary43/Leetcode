class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> res;
        if(words.empty()) return res;

        int wordLen = words[0].size();
        int k = words.size();
        int totalLen = wordLen * k;

        unordered_map<string,int> wordCount;
        for(auto &w:words) wordCount[w]++;

        for(int i=0;i<wordLen;i++){

            int left=i, count=0;
            unordered_map<string,int> window;

            for(int right=i; right+wordLen<=s.size(); right+=wordLen){

                string word = s.substr(right,wordLen);

                if(wordCount.count(word)){
                    window[word]++;
                    count++;

                    while(window[word] > wordCount[word]){
                        string leftWord = s.substr(left,wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if(count==k){
                        res.push_back(left);
                    }
                }
                else{
                    window.clear();
                    count=0;
                    left = right + wordLen;
                }
            }
        }
        return res;
    }
};