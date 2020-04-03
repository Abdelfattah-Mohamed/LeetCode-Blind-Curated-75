class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool row = false, col = false;
        for(int i = 0; i < n; i++) {
            if(!matrix[i][0]) col = true;
            for(int j = 0; j < m; j++) {
                if(!i && !matrix[0][j]) row = true;
                if(!matrix[i][j]) matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for(int i = 1; i < n; i++) {
            if(!matrix[i][0]) {
                for(int &x : matrix[i]) x = 0;
            }
        }
        for(int j = 1; j < m; j++) {
            if(!matrix[0][j]) {
                for(int i = 0; i < n; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(row) {
            for(int &x : matrix[0]) x = 0;
        }
        if(col) {
            for(int i = 0; i < n; i++) matrix[i][0] = 0;
        }
    }
};
​
​
/*
​
    Time Complexity  => O(n * m)
    Space Complexity => O(1)
​
*/
