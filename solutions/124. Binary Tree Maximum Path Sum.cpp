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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        helper(root);
        return max(root->val, ans);
    }
    
    void helper(TreeNode* root) {
        if(!root) return;
        helper(root->left);
        helper(root->right);
        if(root->left && root->right) ans = max(ans, root->val + root->left->val + root->right->val);
        int x = root->val;
        if(root->left) root->val= max(root->val, x + root->left->val);
        if(root->right) root->val= max(root->val, x + root->right->val);
        ans = max(ans, root->val);
    }
};
​
​
/*
​
    Time Complexity  => O(n)
    Space Complexity => O(n)   Recursion.
​
​
*/
