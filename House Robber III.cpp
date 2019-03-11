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
    int max(int a, int b) {
        return (a<b)?b:a;
    }
    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        // do not rob current root
        int r1 = rob0(root);
        // rob current root
        int r2 = root->val + rob0(root->left) + rob0(root->right);
        return max(r1, r2);
    }
    int rob0(TreeNode* root) {
        if(root == NULL)
            return 0;
        return rob(root->left) + rob(root->right);
    }

};