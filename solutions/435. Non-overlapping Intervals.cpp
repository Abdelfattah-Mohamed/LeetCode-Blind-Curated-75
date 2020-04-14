class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int> pq;
        int ans = 0;
        for(auto x : intervals) {
            if(pq.empty()) pq.push(x[1]);
            else {
                if(x[0] < pq.top()) {
                    ans++;
                    if(x[1] < pq.top()) {
                        pq.pop();
                        pq.push(x[1]);
                    }
                } else {
                    pq.pop();
                    pq.push(x[1]);
                }
            }
        }
        return ans;
    }
};
​
/*
​
    Time Complexity  => O(nlg(n))
    Space Complexity => O(n)
​
*/
