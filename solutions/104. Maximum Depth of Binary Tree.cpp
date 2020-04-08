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
    int maxDepth(TreeNode* root) {
        int ans = 0;
        if(!root) return ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int len = que.size();
            ans++;
            while(len--) {
                TreeNode* x = que.front();
                que.pop();
                if(x->left) que.push(x->left);
                if(x->right) que.push(x->right);
            }
        }
        return ans;
    }
};
​
/*
​
    Time Complexity  => O(n)
    Space Complexity => O(n)
​
*/
