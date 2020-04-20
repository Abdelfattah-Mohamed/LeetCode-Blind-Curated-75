class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> x = nums;
        nums[1] = max(nums[0], nums[1]);
        x[2] = max(x[1], x[2]);
        for(int i = 2; i < n - 1; i++) nums[i] = max(nums[i - 2] + nums[i], nums[i - 1]);
        for(int i = 3; i < n; i++) x[i] = max(x[i - 2] + x[i], x[i - 1]);
        return max(nums[n - 2], x[n - 1]);
    }
};
​
​
/*
​
    Time Complexity  => O(n)
    Space Complexity => O(n)
​
*/
