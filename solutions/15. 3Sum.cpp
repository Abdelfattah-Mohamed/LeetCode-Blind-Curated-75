class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) mp[nums[i]] = i;
        vector<vector<int>> vec;
        for(int i = 0; i < n - 2; i++) {
            if(nums[i] + nums[i + 1] + nums[i + 2] > 0) return vec;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n - 1; j++) {
                if(nums[i] + nums[j] + nums[j + 1] > 0) break;
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
