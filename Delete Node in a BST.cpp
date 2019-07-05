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
    TreeNode* leftmost(TreeNode* p) {
        if(p->left == NULL)
            return p;
        TreeNode* last = p;
        while(p->left != NULL) {
            last = p;
            p = p->left;
        }
        last->left = p->right;
        return p;
    }
    TreeNode* rightmost(TreeNode* p) {
        if(p->right == NULL)
            return p;
        TreeNode* last = p;
        while(p->right != NULL) {
            last = p;
            p = p->right;
        }
        last->right = p->left;
        return p;
    }
    TreeNode* delNode(TreeNode* p, TreeNode* parent) {
        TreeNode* np;
        if(p->left == NULL && p->right == NULL) {
            if(parent->left == p)
                parent->left = NULL;
            else parent->right = NULL;
        }
        else if(p->left == NULL) {
            np = leftmost(p->right);
            if(np != p->right)
                np->right = p->right;
            np->left = p->left;
            if(p == parent->left)
                parent->left = np;
            else parent->right = np;
        }
        else {
            np = rightmost(p->left);
            if(np != p->left)
                np->left = p->left;
            np->right = p->right;
            if(p == parent->left)
                parent->left = np;
            else parent->right = np;
        }
        return parent;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* np;
        if(root != NULL && root->val == key) {
            if(root->left == NULL && root->right == NULL)
                return NULL;
            else if(root->left == NULL)
                return root->right;
            else if(root->right == NULL)
                return root->left;
            else {
                np = leftmost(root->right);
                if(np != root->right)
                    np->right = root->right;
                np->left = root->left;
                return np;
            }
        }
        TreeNode* p = root;
        TreeNode* last = NULL;
        while(p != NULL) {
            if(p->val == key) {
                delNode(p, last);
                return root;
            }
            else if(p->val > key) {
                last = p;
                p = p->left;
            }
            else {
                last = p;
                p = p->right;
            }
        }
        return root;
    }
};