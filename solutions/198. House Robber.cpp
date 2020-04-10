class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        if(n == 1) return nums[0];
        nums[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++) nums[i] = max(nums[i] + nums[i - 2], nums[i - 1]);
        return nums[n - 1];
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
