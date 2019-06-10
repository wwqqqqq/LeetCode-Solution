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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        if(root->left != NULL) {
            vector<int> temp = inorderTraversal(root->left);
            result.insert(result.end(), temp.begin(), temp.end());
        }
        result.push_back(root->val);
        if(root->right != NULL) {
            vector<int> temp = inorderTraversal(root->right);
            result.insert(result.end(), temp.begin(), temp.end());
        }
        return result;
    }
};