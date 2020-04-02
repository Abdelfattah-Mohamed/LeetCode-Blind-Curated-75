                }
            }
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()) {
            pair<int, int> temp = pq.top();
            pq.pop();
            ans.push_back({temp.second, temp.first});
        }
        sort(ans.begin(), ans.end());
        return ans;
        
        
    }
    
    pair<int, int> get_over(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int l = -1, r = -1;
        int mini = newInterval[0], maxi = newInterval[1];
        for(int i = 0; i < n; i++) {
            if(lop(intervals[i], newInterval)) {
                if(intervals[i][0] < mini) {
                    mini = intervals[i][0];
                    l = i;
                }
                if(intervals[i][1] > maxi) {
                    maxi = intervals[i][1];
                    r = i;
                }
            }
        }
        return {l, r};
    }
    
    bool lop(vector<int> x, vector<int> y) {
        if(x[0] < y[0] && x[1] < y[0]) return false;
        if(y[0] < x[0] && y[1] < x[0]) return false;
        if(x[1] > y[1] && x[0] > y[1]) return false;
        if(y[1] > x[1] && y[0] > x[1]) return false;
        return true;
    }
    
    vector<int> over(pair<int, int> x, pair<int, int> y) {
        if(y.second <= x.first) return {max(y.first, x.first), x.second};
        return {};
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
