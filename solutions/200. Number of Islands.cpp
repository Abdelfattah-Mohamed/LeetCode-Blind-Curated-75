class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(!n) return 0;
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '0') continue;
                queue<pair<int, int>> que;
                que.push({i, j});
                grid[i][j] = '0';
                while(!que.empty()) {
                    int x = que.front().first, y = que.front().second;
                    que.pop();
                    if(x > 0 && grid[x - 1][y] == '1') grid[x - 1][y] = '0', que.push({x - 1, y}); 
                    if(x < n  - 1 && grid[x + 1][y] == '1') grid[x + 1][y] = '0', que.push({x + 1, y}); 
                    if(y > 0 && grid[x][y - 1] == '1') grid[x][y - 1] = '0', que.push({x, y - 1}); 
                    if(y < m - 1 && grid[x][y + 1] == '1') grid[x][y + 1] = '0', que.push({x, y + 1}); 
                }
                ans++;
            }
        }
        return ans;
    }
};
​
​
/*
​
    Time Complexity  => O(n * m)
    Space Complexity => O(n * m)
​
*/
