class Solution {
public:
    string longestPalindrome(string s) {
        string temp = "#";
        for(char c : s) temp += c, temp += '#';
        int n = temp.size();
        int ans = 0;
        int ansl = 0, ansr = 0;
        for(int i = 0; i < n; i++) {
            int l = i - 1, r = i + 1;
            while(l >= 0 && r < n && temp[l] == temp[r]) l--, r++;
            if((r - l) > ans) {
                ans = (r - l);
                ansl = l, ansr = r;
            }
        }
        string ret = "";
        ansl += 2;
        ansr--;
        while(ansl < ansr) {
            ret += temp[ansl];
            ansl += 2;
        }
        return ret;
    }
};
​
/*
    Time Complexity  => O(n^2)
    Space Complexity => O(1)
    
    -----------------------------------
    
    optimal one : (Manacher's Algorithm)
        Time Complexity  => O(n)
        Space Complexity => O(n)
*/
