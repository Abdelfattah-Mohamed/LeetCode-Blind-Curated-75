class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int x = 32;
        while(n) {
            ans <<= 1;
            ans += (n & 1);
            n >>= 1;
            x--;
        }
        while(x--) ans <<= 1;
        return ans;
    }
};
​
​
/*
​
    Time Complexity  => O(1)
    Space Complexity => O(1)
​
*/
