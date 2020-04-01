class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return true;
        int maxi = 0;
        for(int i = 0; i < n - 1; i++) {
            if(i > maxi) return false;
            if(nums[i]) {
                if(nums[i] + i >= n - 1) return true;
                maxi = max(maxi, nums[i] + i);
            }
        }
        return false;
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
