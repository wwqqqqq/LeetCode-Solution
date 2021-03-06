/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root, int val) {
        if(root == NULL)
            return true;
        if(root->val != val)
            return false;
        if(!isUnivalTree(root->left, val))
            return false;
        if(!isUnivalTree(root->right, val))
            return false;
        return true;
    }
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL)
            return true;
        return isUnivalTree(root, root->val);
    }
};