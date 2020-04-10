class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            ans = min(ans, nums[mid]);
            if(nums[l] > nums[r] && nums[mid] > nums[r]) l = mid + 1;
            else r = mid - 1;
        }
        return ans;
    }
};
​
​
/*
​
    Time Complexity  => O(lg(n))
    Space Complexity => O(1)
​
*/
