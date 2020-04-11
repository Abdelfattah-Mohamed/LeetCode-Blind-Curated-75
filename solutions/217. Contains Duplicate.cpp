class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int x : nums) st.emplace(x);
        return nums.size() != st.size();
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
