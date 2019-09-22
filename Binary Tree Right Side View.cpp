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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        result.push_back(root->val);
        if(root->left == NULL && root->right == NULL)
            return result;
        if(root->left == NULL) {
            vector<int> right = rightSideView(root->right);
            result.insert(result.end(), right.begin(), right.end());
            return result;
        }
        if(root->right == NULL) {
            vector<int> left = rightSideView(root->left);
            result.insert(result.end(), left.begin(), left.end());
            return result;
        }
        vector<int> left = rightSideView(root->left);
        vector<int> right = rightSideView(root->right);
        result.insert(result.end(), right.begin(), right.end());
        if(left.size() <= right.size()) {
            return result;
        }
        result.insert(result.end(), left.begin() + right.size(), left.end());
        return result;
    }
};