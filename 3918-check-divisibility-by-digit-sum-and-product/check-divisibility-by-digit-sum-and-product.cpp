class Solution {
public:
    bool checkDivisibility(int n) {

        if(n <= 0) return false;
        int digitSum = 0;
        int digitProduct = 1;
        int orgN = n;
        while(n > 0) {
            int digit = n % 10;
            digitSum += digit;
            digitProduct *= digit;

            n /= 10;
        }
        int totalSum = digitSum + digitProduct;

        if((orgN % totalSum) != 0) {
            return false;
            
        }
        return true;
    }
};