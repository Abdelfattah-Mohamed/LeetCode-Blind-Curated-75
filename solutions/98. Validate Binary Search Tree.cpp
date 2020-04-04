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
    vector<int> vec;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        inorder(root);
        int n = vec.size();
        for(int i = 1; i < n; i++) {
            if(vec[i] <= vec[i - 1]) return false;
        }
        return true;
    }
    
    void inorder(TreeNode* x) {
        if(x->left) inorder(x->left);
        vec.push_back(x->val);
        if(x->right) inorder(x->right);
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
