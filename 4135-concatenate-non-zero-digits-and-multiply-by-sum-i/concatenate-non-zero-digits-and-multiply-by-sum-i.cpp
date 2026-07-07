class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x =0;
        int sum =0;
        long long rev = 0;
        while(n>0){
            int digit =  n%10;

            if(digit!=0){
               rev = rev * 10 + digit;
                sum += digit;
            }
            n/=10;
        }
        while(rev > 0){
            x = x * 10 + (rev % 10);
            rev /= 10;
        }
        return x * sum;

    }
};