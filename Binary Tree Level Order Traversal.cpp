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
    void visitTree(vector<TreeNode*>& nodes, vector<vector<int>>& res) {
        int size = nodes.size();
        if(size == 0)
            return;
        vector<int> thisLevel;
        //vector<TreeNode*> next;
        for(int i=0;i<size;i++) {
            if(nodes[i] == NULL)
                continue;
            thisLevel.push_back((nodes[i])->val);
            if(nodes[i]->left != NULL)
                nodes.push_back(nodes[i]->left);
            if(nodes[i]->right != NULL)
                nodes.push_back(nodes[i]->right);
        }
        nodes.erase(nodes.begin(), nodes.begin() + size);
        res.push_back(thisLevel);
        visitTree(nodes, res);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> tree;
        tree.push_back(root);
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        visitTree(tree, res);
        return res;
    }
};