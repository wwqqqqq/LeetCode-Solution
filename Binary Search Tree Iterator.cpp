/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        TreeNode* p = root;
        while(p != NULL) {
            s.push(p);
            p = p->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* p = s.top();
        int result = p->val;
        if(p->right != NULL) {
            p = p->right;
            while(p != NULL) {
                s.push(p);
                p = p->left;
            }
        }
        else {
            s.pop();
            if(s.size() == 0)
                return result;
            TreeNode* parent = s.top();
            while(parent->right == p) {
                s.pop();
                p = parent;
                if(s.size() == 0)
                    break;
                parent = s.top();
            }
        }
        return result;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(s.size() > 0)
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */