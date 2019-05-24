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
    int difference(int n1, int n2) {
        if(n1-n2 < 0)
            return n2-n1;
        return n1-n2;
    }
    void bfs(TreeNode* root, set<int> &elements) {
        if(root == NULL)
            return;
        elements.insert(root->val);
        bfs(root->left, elements);
        bfs(root->right, elements);
    }
    int getMinimumDifference(TreeNode* root) {
        set<int> elements;
        bfs(root, elements);
        auto iter1 = elements.begin();
        auto iter2 = elements.begin();
        iter2++;
        int min = 2147483647;
        for(;iter2!=elements.end(); iter1++, iter2++) {
            int d = difference(*iter1, *iter2);
            if(d < min) min = d;
        }
        return min;
    }
};