class Solution {
public:
    int arrangeCoins(int n) {
       int k =1, i = k;
        while(k <= n){
            n= n-k;
            k++;
            
        }
        return k-1;
    }
};