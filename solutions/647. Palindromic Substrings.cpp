class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<pair<int, bool>>> dp(n, vector<pair<int, bool>>(n, {0, true}));
        for(int i = 0; i < n; i++) dp[i][i] = {1, true};
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n - i; j++) {
                if(s[j] == s[i + j]) {
                    dp[j][i + j] = {dp[j][i + j - 1].first + dp[j + 1][i + j].first - dp[j + 1][i + j - 1].first, false};
                    if(dp[j + 1][i + j - 1].second) dp[j][i + j] = {dp[j][i + j].first + 1, true};
                } 
                else dp[j][i + j] = {dp[j][i + j - 1].first + dp[j + 1][i + j].first - dp[j + 1][i + j - 1].first, false};
            }
        }
        return dp[0][n - 1].first;
    }
};
​
/*
    Time Complexity  => O(n^2)
    Space Complexity => O(n^2)
    
    -----------------------------------
    
    optimal one : (Manacher's Algorithm)
        Time Complexity  => O(n)
        Space Complexity => O(n)
*/
