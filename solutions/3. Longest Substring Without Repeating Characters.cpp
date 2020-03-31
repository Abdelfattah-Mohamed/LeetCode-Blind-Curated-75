class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        unordered_set<char> st;
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            while(st.count(s[i])) {
                ans = max(ans, i - l);
                st.erase(s[l]);
                l++;
            }
            st.emplace(s[i]);
        }
        return max(ans, (int) st.size());
    }
};
​
/*
    Time Complexity  => O(n)
    Space Complexity => O(1)
*/
