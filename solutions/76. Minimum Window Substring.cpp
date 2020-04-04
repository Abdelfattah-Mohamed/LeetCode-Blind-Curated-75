class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty() || s.empty()) return "";
        unordered_map<char, int> mp;
        for(char c : t) mp[c]++;
        int n = s.size();
        int l = 0, r = 0, mini = INT_MAX, ansL = 0;
        int count = t.size();
        
        while(r < s.size()) {
            if(mp[s[r]] > 0) count--;
            mp[s[r]]--, r++;
            while(!count) {
                if(r - l < mini) mini = r - l, ansL = l;
                if(!mp[s[l]]) count++;
                mp[s[l]]++, l++;
            }
        }
        
        if(mini > (int) 1e8) return "";
        string ans = "";
        for(int i = ansL; i < mini + ansL; i++) ans += s[i];
        return ans;
    }
};
​
/*
    
    Time Complexity  => O(n)
    Space Complexity => O(m)
​
   
*/
