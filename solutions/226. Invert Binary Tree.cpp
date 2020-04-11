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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            TreeNode* x =  que.front();
            que.pop();
            swap(x->left, x->right);
            if(x->left) que.push(x->left);
            if(x->right) que.push(x->right);
        }
        return root;
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
