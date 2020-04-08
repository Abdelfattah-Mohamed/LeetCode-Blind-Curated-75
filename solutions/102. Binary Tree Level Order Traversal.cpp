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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int len = que.size();
            vector<int> temp;
            while(len--) {
                TreeNode* x = que.front();
                que.pop();
                temp.push_back(x->val);
                if(x->left) que.push(x->left);
                if(x->right) que.push(x->right);
            }
            ans.push_back(temp);
        }
        return ans;
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
