class Solution {
public:
    int findProduct(int num) {

        int product = 1;
        while (num > 0) {
            int digit = num % 10;
            product *= digit;

            if(product == 0) return 0;  // slight optimization 
            num /= 10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {

        for (int i = n; i <= n + 10;
             i++) { // i <= n + 10 becoz  will come within steps and that makes
                    // the product  , therefore alwas divisible
            if (findProduct(i) % t == 0) {
                return i;
            }
        }
        return -1;
    }
};