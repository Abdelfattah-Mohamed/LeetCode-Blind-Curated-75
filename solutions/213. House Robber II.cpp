class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        if(n == 1) return nums[0];
        return max(solver(nums, 0, n - 1), solver(nums, 1, n));
    }
    
    int solver(vector<int> &nums, int l, int r) {
        int prev = 0, curr = 0;
        while(l < r) {
            int temp = max(curr, prev + nums[l++]);
            prev = curr, curr = temp;
        }
        return curr;
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
