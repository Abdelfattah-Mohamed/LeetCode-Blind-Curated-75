class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while(l < r) {
            char c1 = s[l], c2 = s[r];
            if(c1 >= 'A' && c1 <= 'Z') c1 += ('a' - 'A');
            if(c2 >= 'A' && c2 <= 'Z') c2 += ('a' - 'A');
            if(!(c1 >= 'a' && c1 <= 'z') && !(c1 >= '0' && c1 <= '9')) {
                l++;
                continue;
            }
            if(!(c2 >= 'a' && c2 <= 'z') && !(c2 >= '0' && c2 <= '9')) {
                r--;
                continue;
            }
            if((c1 >= 'a' && c1 <= 'z' || c1 >= '0' && c1 <= '9') && (c2 >= 'a' && c2 <= 'z' || c2 >= '0' && c2 <= '9') && c1 != c2) return false;
            else l++, r--;
        }
        return true;
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
