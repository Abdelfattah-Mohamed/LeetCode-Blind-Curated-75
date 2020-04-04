class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> vec(n, 1);
        for(int i = 1; i < n; i++) {
            if(s[i] == '0') {
                if(s[i - 1] == '1' || s[i - 1] == '2') {
                    if(i > 1) vec[i] = vec[i - 2];
                    else vec[i] = 1;
                } else return 0;
            } else {
                vec[i] = vec[i - 1];
                if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                    if(i == 1) vec[i]++;
                    else vec[i] += vec[i - 2];
                }
            }   
        }
        return (s[0] == '0' ? 0 : vec[n - 1]);
    }
};
​
​
/*
​
    Time Complexity  => O(n)
    Space Complexity => O(n)
​
*/
