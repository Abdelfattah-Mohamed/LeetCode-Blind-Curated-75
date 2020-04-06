class Solution {
public:
    int getSum(int a, int b) {
        while(b) {
            int carry = a & b;
            a = a ^ b;
            b = (carry & INT_MAX) << 1;
        }
        return a;
    }
};
​
/*
    
    Time Complexity  => O(lg(b))
    Space Complexity => O(1)
    
​
*/
