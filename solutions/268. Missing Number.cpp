class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            while(i != nums[i]) {
                if(nums[i] >= n) break;
                swap(nums[i], nums[nums[i]]);
            }
        }
        for(int i = 0; i < n; i++) {
            if(i != nums[i]) return i;
        }
        return n;
    }
};
​
​
​
/*
​
    Time Complexity  => O(n)
    Space Complexity => O(1)
​
*/
