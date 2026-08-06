class Solution {
public:
    int smallestNumber(int n, int t) {

        //we will strart form n and then take out digits of n ..and do their product ..and if it is divisible by t 
        int curr = n;

        while(true) {
            int product = 1;
            int temp = curr;

            while(temp > 0) {
                int digit = temp % 10;
                product *= digit;
                temp /= 10;

            }
            if(product % t == 0) {
                return curr;
            }
            curr++;
        }
        
    }
};