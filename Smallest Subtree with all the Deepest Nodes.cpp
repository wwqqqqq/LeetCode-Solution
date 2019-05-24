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
    int depth(TreeNode* root, map<TreeNode*, int> &dmap) {
        if(root == NULL)
            return 0;
        int left_d = depth(root->left, dmap);
        int right_d = depth(root->right, dmap);
        int d = ((left_d > right_d)?left_d:right_d) + 1;
        dmap.insert(pair<TreeNode*, int>(root, d));
        return d;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        map<TreeNode*, int> dmap;
        depth(root, dmap);
        while(root != NULL) {
            if(root -> left == NULL && root -> right == NULL)
                break;
            if(root -> left == NULL)
                root = root->right;
            else if(root -> right == NULL)
                root = root -> left;
            else {
                auto left_iter = dmap.find(root->left);
                auto right_iter = dmap.find(root->right);
                if(left_iter->second == right_iter->second)
                    break;
                else if(left_iter->second > right_iter->second)
                    root = root -> left;
                else root = root -> right;
            }
        }
        return root;
    }
};