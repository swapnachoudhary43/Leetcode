class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map< int , int> mpp;
        int l =0 ,maxlen = 0;

        for(int r =0; r < fruits.size(); r++){
            mpp[fruits[r]]++;

        while(mpp.size()>2){
            mpp[fruits[l]]--;
            if(mpp[fruits[l]]==0){
            mpp.erase(fruits[l]);
            }
            l++;
        }
        maxlen = max(maxlen , r-l+1);
        }
        return maxlen;
    }
};