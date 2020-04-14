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
    bool ans = false;
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!t) return true;
        if(!s) return false;
        trav(s, t);
        return ans;
    }
    
    void trav(TreeNode* s, TreeNode* t) {
        if(!s) return;
        if(s->val == t->val) ans |= check(s, t);
        trav(s->left, t);
        trav(s->right, t);
    }
    
    bool check(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        else if(!s || !t) return false;
        return ((s->val == t->val) && check(s->left, t->left) && check(s->right, t->right));
    }
};
​
​
/*
​
    Time Complexity  => O(n * m)
    Space Complexity => O(n + m)
​
*/
