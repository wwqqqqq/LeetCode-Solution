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
    TreeNode* deleteNode(TreeNode* node)
    {
        if(node==NULL) return NULL;
        if(node->left==NULL) 
        {
            return node->right;
        }
        if(node->right==NULL) 
        {
            return node->left;
        }
        TreeNode* p=node->right;
        if(p->left==NULL)
        {
            p->left=node->left;
            node->left=NULL;
            node->right=NULL;
            return p;
        }
        TreeNode* q;
        while(p->left!=NULL)
        {
            q=p;
            p=p->left;
        }
        q->left=p->right;
        p->right=node->right;
        p->left=node->left;
        node->left=NULL;
        node->right=NULL;
        return p;
    }
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        //while(root!=NULL&&(root->val<L||root->val>R)) root=deleteNode(root);
        if(root==NULL) return NULL;
        root->left=trimBST(root->left,L,R);
        root->right=trimBST(root->right,L,R);
        while(root!=NULL&&(root->val<L||root->val>R)) root=deleteNode(root);
        if(root==NULL) return NULL;
        return root;
    }
};