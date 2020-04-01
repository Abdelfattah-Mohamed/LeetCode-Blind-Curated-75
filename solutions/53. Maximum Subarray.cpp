class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int sum = nums[0];
        for(int i = 1; i < n; i++) {
            ans = max(ans, sum);
            if(sum < 0) sum = nums[i];
            else sum += nums[i];
        }
        return max(ans, sum);
    }
};
​
/*
    
    Time Complexity  => O(n)
    Space Complexity => O(1)
​
*/
