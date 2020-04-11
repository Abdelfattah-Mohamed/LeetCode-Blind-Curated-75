/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        help(root, k);
        return ans;
    }
    
    void help(TreeNode* root, int &k) {
        if(!root) return;
        help(root->left, k);
        k--;
        if(!k) ans = root->val;
        help(root->right, k);
    }
};
​
/*
​
    Time Complexity  => O(n)
    Space Complexity => O(n)
​
*/
