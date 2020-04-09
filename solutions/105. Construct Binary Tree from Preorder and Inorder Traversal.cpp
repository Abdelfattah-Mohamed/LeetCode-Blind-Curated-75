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
    unordered_map<int, int> mp;
​
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) mp[inorder[i]] = i;
        return construct(preorder, inorder, 0);
    }
​
    TreeNode *construct(vector<int> &preorder, vector<int> &inorder, int add) {
        int n = preorder.size(), m = inorder.size();
        if (!n) return NULL;
​
        TreeNode *x = new TreeNode(preorder[0]);
        int idx = mp[x->val] - add;
​
        vector<int> pLeft(preorder.begin() + 1, preorder.begin() + idx + 1);
        vector<int> iLeft(inorder.begin(), inorder.begin() + idx);
        x->left = construct(pLeft, iLeft, add);
​
        vector<int> pRight(preorder.begin() + idx + 1, preorder.end());
        vector<int> iRight(inorder.begin() + idx + 1, inorder.end());
        x->right = construct(pRight, iRight, mp[x->val] + 1);
​
        return x;
    }
​
};
​
/*
​
    Time Complexity  => O(n)
    Space Complexity => O(n)
​
*/
