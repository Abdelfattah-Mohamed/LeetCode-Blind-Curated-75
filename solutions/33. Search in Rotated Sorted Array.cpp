class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) {
                if(nums[l] > nums[mid] || nums[l] <= target) r = mid - 1;
                else l = mid + 1;
            } else {
                if(nums[r] < nums[mid] || nums[r] >= target) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};
​
​
/*
    Time Complexity  => O(lg(n))
    Space Complexity => O(1)
    
*/
