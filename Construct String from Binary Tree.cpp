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
    string tree2str(TreeNode* t) {
        string result;
        if(t == NULL)
            return result;
        result = to_string(t->val);
        if(t->left == NULL && t->right != NULL)
            result.append("()");
        else if(t->left != NULL) {
            result.append("(");
            result.append(tree2str(t->left));
            result.append(")");
        }
        
        if(t->right != NULL) {
            result.append("(");
            result.append(tree2str(t->right));
            result.append(")");
        }
        
        return result;
    }
};