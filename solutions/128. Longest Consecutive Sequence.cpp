class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(int x : nums) mp[x] = true;
        int ret = 0;
        for(int x : nums) {
            int sum = 0;
            if(mp[x]) {
                for(int i = x; true; i--) {
                    if(!mp[i]) break;
                    sum++, mp[i] = false;
                }
                
                for(int i = x + 1; true; i++) {
                    if(!mp[i]) break;
                    sum++, mp[i] = false;
                }
            }
            ret = max(ret, sum);
        }
        return ret;
    }
};
​
​
/*
    
    Time Complexity  => O(n)
    Space Complexity => O(n)
   
*/
