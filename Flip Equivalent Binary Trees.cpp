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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL)
            return true;
        else if(root1 == NULL || root2 == NULL)
            return false;
        if(root1->val != root2->val)
            return false;
        if(flipEquiv(root1->left, root2->left)) {
            if(flipEquiv(root1->right, root2->right))
                return true;
            else return false;
        }
        else {
            if(flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left))
                return true;
            else return false;
        }
        return false;
    }
};