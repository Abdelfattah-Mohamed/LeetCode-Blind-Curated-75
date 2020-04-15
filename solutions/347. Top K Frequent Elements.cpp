class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int x : nums) mp[x]++;
        priority_queue<pair<int, int>> pq;
        for(auto x : mp) {
            if(pq.size() < k) pq.push({-x.second, x.first});
            else {
                if(x.second > abs(pq.top().first)) {
                    pq.pop();
                    pq.push({-x.second, x.first});
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()) ans.push_back(pq.top().second), pq.pop();
        return ans;
    }
};
​
​
/*
​
    Time Complexity  => O(nlg(k))
    Space Complexity => O(n + lg(k))
​
*/
