class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ret;
        back(candidates, target, ret, 0);
        return ans;
    }
    
    void back(vector<int>& vec, int x, vector<int>& ret, int i) {
        if(x < 0) return;
        if(x == 0) {
            ans.push_back(ret);
            return;
        }
        
        for(; i < vec.size(); i++) {
            ret.push_back(vec[i]);
            back(vec, x - vec[i], ret, i);
            ret.pop_back();
        }
    }
};
​
​
/*
    Time Complexity  => O(n^2)
    Space Complexity => O(n^2)
    
*/
