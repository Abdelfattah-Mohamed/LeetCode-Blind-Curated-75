class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st;
        for(string s : wordDict) st.emplace(s);
        vector<bool> dp(n, false);
        for(int i = -1; i < n; i++) {
            string temp = "";
            if(i == -1 || dp[i]) {
                for(int j = i + 1; j < n; j++) {
                    if(st.count(temp)) dp[j - 1] = true;
                    temp += s[j];
                }
                if(st.count(temp)) return true;
            }
            if(dp[n - 1]) return true;
        }
        for(bool x : dp) cout << x << " ";
        return dp[n - 1];
    }
};
​
​
/*
​
    Time Complexity  => O(n^2)
    Space Complexity => O(n)
​
*/
