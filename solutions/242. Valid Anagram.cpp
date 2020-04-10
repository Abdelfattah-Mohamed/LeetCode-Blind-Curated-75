class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if(n != t.size()) return false;
        vector<int> vec(26, 0);
        for(int i = 0; i < n; i++) vec[s[i] - 'a']++, vec[t[i] - 'a']--;
        for(int x : vec) if(x) return false;
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
