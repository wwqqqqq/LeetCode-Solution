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
    int tilt;
    int sum(TreeNode* root)
    {
        if(root==NULL) return 0;
        int lsum=sum(root->left);
        int rsum=sum(root->right);
        int dis=lsum-rsum;
        if(dis<0) dis=-dis;
        tilt+=dis;
        return lsum+rsum+root->val;
        
    }
    int findTilt(TreeNode* root) {
        if(root==NULL) return 0;
        tilt=0;
        sum(root);
        return tilt;
    }
};