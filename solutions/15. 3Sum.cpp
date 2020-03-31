class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) mp[nums[i]] = i;
        vector<vector<int>> vec;
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n; j++) {
                if(nums[j] == nums[j - 1] && j != i + 1) continue;
                int x = 0 - nums[i] - nums[j];
                if(mp.count(x) && mp[x] > i && mp[x] > j) {
                    vec.push_back({nums[i], nums[j], x}); 
                }
            }
        }
        return vec;
    }
};
​
/*
    Time Complexity  => O(n^2)
    Space Complexity => O(n)
*/
