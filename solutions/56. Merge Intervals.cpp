class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<vector<int>> pq;
        for(auto x : intervals) {
            swap(x[0], x[1]);
            if(pq.empty()) pq.push(x);
            else {
                int a = pq.top()[1];
                int b = pq.top()[0];
                if(over(x, pq.top())) {    
                    pq.pop();
                    pq.push({max(x[0], b), a});
                }
                else pq.push(x);
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            vector<int> x = pq.top();
            ans.push_back({x[1], x[0]});
            pq.pop();
        }
        return ans;
    }
    
    bool over(vector<int> x, vector<int> y) {
        return abs(x[1]) <= abs(y[0]);
    }
};
​
​
/*
​
    Time Complexity  => O(nlg(n))
    Space Complexity => O(n)
​
​
*/
