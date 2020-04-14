class Solution {
public:
    int characterReplacement(string s, int K) {
        int n = s.size();
        if(!n) return 0;
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            char c = 'A' + i;
            int l = 0, r = 0;
            int k = K;
            while(r <= n) {
                while(r < n && s[r] == c) r++;
                ans = max(ans, (r - l));
                while(!k) {
                    if(s[l++] != c) k++;
                }
                if(r < n && s[r] != c) k--;
                r++;
            }
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
