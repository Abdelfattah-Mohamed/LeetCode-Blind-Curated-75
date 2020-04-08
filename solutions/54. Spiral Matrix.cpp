class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(!n) return {};
        if(n == 1) return matrix[0];
        int m = matrix[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<int> ret;
        for(int i = 0; 2 * i <= min(n, m); i++) {
            for(int j = i; j < m - i - 1; j++) if(!visited[i][j]) ret.push_back(matrix[i][j]), visited[i][j] = true;
            for(int j = i; j < n - i - 1; j++) if(!visited[j][m - i - 1]) ret.push_back(matrix[j][m - i - 1]), visited[j][m - i - 1] = true;
            for(int j = m - i - 1; j > i; j--) if(!visited[n - i - 1][j]) ret.push_back(matrix[n - i - 1][j]), visited[n - i - 1][j] = true;
            for(int j = n - i - 1; j > i; j--) if(!visited[j][i]) ret.push_back(matrix[j][i]), visited[j][i] = true;
        }
        if(n%2 && n == m) ret.push_back(matrix[n / 2][m / 2]);
        return ret;
    }
};
​
​
/*
​
    Time Complexity  => O(n * m)
    Space Complexity => O(n * m)
​
​
*/
