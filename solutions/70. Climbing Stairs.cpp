class Solution {
public:
    int climbStairs(int n) {
        int f = 1, e = 1;
        n--;
        while(n--) {
            swap(f, e);
            e += f;
        }
        return e;
    }
};
​
​
/*
    
    Time Complexity  => O(n)
    Space Complexity => O(1)
​
*/
