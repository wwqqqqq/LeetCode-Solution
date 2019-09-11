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
    void addPValue(TreeNode* root, int pvalue) {
        if(root == NULL)
            return;
        root->val = root->val + pvalue;
        addPValue(root->left, pvalue);
        addPValue(root->right, pvalue);
    }
    int getSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        int sum = root->val;
        sum += getSum(root->left) + getSum(root->right);
        return sum;
    }
    int bstToGstwithP(TreeNode* root, int pvalue) {
        if(root == NULL)
            return 0;
        int sum = getSum(root);
        int rightSum = bstToGstwithP(root->right, 0);
        root->val += rightSum;
        bstToGstwithP(root->left, root->val);
        addPValue(root, pvalue);
        return sum;
    }
    TreeNode* bstToGst(TreeNode* root) {
        bstToGstwithP(root, 0);
        return root;
    }
};