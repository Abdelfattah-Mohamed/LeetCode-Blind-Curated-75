class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n + 1][amount + 1];
        memset(dp, (int) 1e6, sizeof(dp));
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= amount; j++) {
                if(j == 0) dp[i][j] = 0;
                else if(j < coins[i - 1]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
            }
        }
        return (dp[n][amount] > (int) 1e5 ? -1 : dp[n][amount]);
    }
};
​
​
/*
​
    Time Complexity  => O(n * m)
    Space Complexity => O(n * m)
​
*/
