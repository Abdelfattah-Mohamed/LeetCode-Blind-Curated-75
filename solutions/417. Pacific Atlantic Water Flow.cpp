class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(!n) return {};
        int m = matrix[0].size();
        vector<vector<int>> ans;
        vector<vector<pair<bool, bool>>> visited(n, vector<pair<bool, bool>>(m, {false, false}));
        
        queue<pair<int, int>> que;
        for(int i = 0; i < n; i++) que.push({i, 0}), visited[i][0].first = true;
        for(int i = 0; i < m; i++) que.push({0, i}), visited[0][i].first = true;
        while(!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            if(x > 0 && !visited[x - 1][y].first && matrix[x - 1][y] >= matrix[x][y]) visited[x - 1][y].first = true, que.push({x - 1, y});
            if(x < n - 1 && !visited[x + 1][y].first && matrix[x + 1][y] >= matrix[x][y]) visited[x + 1][y].first = true, que.push({x + 1, y});
            if(y > 0 && !visited[x][y - 1].first && matrix[x][y - 1] >= matrix[x][y]) visited[x][y - 1].first = true, que.push({x, y - 1});
            if(y < m - 1 && !visited[x][y + 1].first && matrix[x][y + 1] >= matrix[x][y]) visited[x][y + 1].first = true, que.push({x, y + 1});
        }
        
        for(int i = 0; i < n; i++) que.push({i, m - 1}), visited[i][m - 1].second = true;
        for(int i = 0; i < m; i++) que.push({n - 1, i}), visited[n - 1][i].second = true;
        while(!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            if(x > 0 && !visited[x - 1][y].second && matrix[x - 1][y] >= matrix[x][y]) visited[x - 1][y].second = true, que.push({x - 1, y});
            if(x < n - 1 && !visited[x + 1][y].second && matrix[x + 1][y] >= matrix[x][y]) visited[x + 1][y].second = true, que.push({x + 1, y});
            if(y > 0 && !visited[x][y - 1].second && matrix[x][y - 1] >= matrix[x][y]) visited[x][y - 1].second = true, que.push({x, y - 1});
            if(y < m - 1 && !visited[x][y + 1].second && matrix[x][y + 1] >= matrix[x][y]) visited[x][y + 1].second = true, que.push({x, y + 1});
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(visited[i][j].first && visited[i][j].second) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
​
/*
​
    Time Complexity  => O(n * m)
    Space Complexity => O(n * m)
​
*/
