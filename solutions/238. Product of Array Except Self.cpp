class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n, 1);
        vector<int> vec_2(n, 1);
        for(int i = 1; i < n; i++) vec[i] = vec[i - 1] * nums[i - 1];
        for(int i = n - 2; i >= 0; i--) vec_2[i] = vec_2[i + 1] * nums[i + 1];
        vector<int> ans(n , 1);
        for(int i = 0; i < n; i++) ans[i] = vec[i] * vec_2[i];
        return ans;
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
