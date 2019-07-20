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
    int sumNumbers(TreeNode* root, int prefix) {
        if(root == NULL)
            return 0;
        int sum = prefix * 10 + root->val;
        if(root->left == NULL && root->right == NULL) {
            // root is leaf
            return sum;
        }
        return sumNumbers(root->left, sum) + sumNumbers(root->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
};