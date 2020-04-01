class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        for(int i = 0; i < n / 2; i++) {
            vector<int> temp;
            for(int j = i; j < n - i - 1; j++) temp.push_back(matrix[i][j]);
            for(int j = i; j < n - i - 1; j++) swap(temp[j - i], matrix[j][n - i - 1]);
            for(int j = i; j < n - i - 1; j++) swap(temp[j - i], matrix[n - i - 1][n - j - 1]);
            for(int j = i; j < n - i - 1; j++) swap(temp[j - i], matrix[n - j - 1][i]);
            for(int j = i; j < n - i - 1; j++) swap(temp[j - i], matrix[i][j]);
        }
    }
};
​
​
/*
    Time Complexity  => O(n^2)
    Space Complexity => O(n)
    
    -----------------------------------
    
    optimal one :
        Time Complexity  => O(n^2)
        Space Complexity => O(1)
    
*/
