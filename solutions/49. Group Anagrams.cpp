class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        vector<vector<string>> ans;
        for(string s : strs) {
            vector<int> vec(26, 0);
            for(char c : s) vec[c - 'a']++;
            string temp = "";
            for(int x : vec) temp += (to_string(x));
            if(mp.count(temp)) ans[mp[temp]].push_back(s);
            else mp[temp] = mp.size(), ans.push_back({s});
        }
        return ans;
    }
};
​
/*
    
    Time Complexity  => O(nk)
    Space Complexity => O(nk)
​
*/
​
​
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        vector<vector<string>> ans;
        for(string s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            if(mp.count(temp)) ans[mp[temp]].push_back(s);
            else mp[temp] = mp.size(), ans.push_back({s});
        }
        return ans;
    }
};
​
​
​
/*
    *best in practice*
    Time Complexity  => O(nklg(k))
    Space Complexity => O(nk)
​
*/
