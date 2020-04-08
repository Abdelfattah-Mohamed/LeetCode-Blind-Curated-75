class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        int ans = 0, last = prices[0];
        bool flag = false;
        for(int i = 1; i < n; i++) {
            if(prices[i] > last) ans = max(ans, (prices[i] - last));
            else last = prices[i];
        }
        return ans;
    }
};
​
​
/*
​
    Time Complexity  => O(n)
    Space Complexity => O(1)
​
*/
