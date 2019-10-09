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
    int getLongestPath(TreeNode* root, int pval, bool increase) {
        if(root == NULL)
            return 0;
        if(increase && pval != root->val-1)
            return 0;
        if(!increase && pval != root->val + 1)
            return 0;
        int result = getLongestPath(root->left, root->val, increase) + 1;
        int result2 = getLongestPath(root->right, root->val, increase) + 1;
        if(result2 > result)
            return result2;
        return result;
    }
    int longestConsecutive(TreeNode* root) {
        if(root == NULL)
            return 0;
        int result = 0;
        int left_result = longestConsecutive(root->left);
        if(left_result > result)
            result = left_result;
        int right_result = longestConsecutive(root->right);
        if(right_result > result)
            result = right_result;
        // if the path passes through root node
        int left_len1 = getLongestPath(root->left, root->val, true);
        int left_len2 = getLongestPath(root->left, root->val, false);
        int right_len1 = getLongestPath(root->right, root->val, true);
        int right_len2 = getLongestPath(root->right, root->val, false);
        int increase_path = left_len2 + 1 + right_len1;
        int decrease_path = left_len1 + 1 + right_len2;
        if(increase_path > result)
            result = increase_path;
        if(decrease_path > result)
            result = decrease_path;
        return result;
    }
};