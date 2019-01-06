/*
971. Flip Binary Tree To Match Preorder Traversal
User Accepted: 656
User Tried: 910
Total Accepted: 688
Total Submissions: 2038
Difficulty: Medium
Given a binary tree with N nodes, each node has a different value from {1, ..., N}.

A node in this binary tree can be flipped by swapping the left child and the right child of that node.

Consider the sequence of N values reported by a preorder traversal starting from the root.  Call such a sequence of N values the voyage of the tree.

(Recall that a preorder traversal of a node means we report the current node's value, then preorder-traverse the left child, then preorder-traverse the right child.)

Our goal is to flip the least number of nodes in the tree so that the voyage of the tree matches the voyage we are given.

If we can do so, then return a list of the values of all nodes flipped.  You may return the answer in any order.

If we cannot do so, then return the list [-1].

Example 1:

Input: root = [1,2], voyage = [2,1]
Output: [-1]

Example 2:

Input: root = [1,2,3], voyage = [1,3,2]
Output: [1]

Example 3:

Input: root = [1,2,3], voyage = [1,2,3]
Output: []
 
Note:

1 <= N <= 100
*/

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
    void flipVoyage(TreeNode* root, vector<int>& voyage, int beg, int end, vector<int>& res) {
        TreeNode *p = root;
        if((root == NULL && beg < end) || p -> val != voyage[beg]) {
            res.erase(res.begin(), res.end());
            res.push_back(-1);
            return;
        }
        if(root == NULL && beg >= end)
            return;
        TreeNode *left = p -> left;
        TreeNode *right = p -> right;
        if(beg + 1 >= end) {
            if(left == NULL && right == NULL)
                return;
            res.erase(res.begin(), res.end());
            res.push_back(-1);
            return;
        }
        if(right == NULL) {
            flipVoyage(left, voyage, beg + 1, end, res);
            return;
        }
        if(left == NULL) {
            flipVoyage(right, voyage, beg + 1, end, res);
            return;
        }
        if(right -> val == voyage[beg+1]) {
            root -> left = right;
            root -> right = left;
            left = root -> left;
            right = root -> right;
            res.push_back(root -> val);
        }
        if(left -> val == voyage[beg + 1]) {
            int ind = -1;
            for(int i = beg + 2; i < end; i++) {
                if(voyage[i] == right -> val) {
                    ind = i;
                    break;
                }
            }
            if(ind == -1) {
                res.erase(res.begin(), res.end());
                res.push_back(-1);
                return;
            }
            flipVoyage(left, voyage, beg+1, ind, res);
            if(res.size()==1 && res[0]==-1)
                return;
            flipVoyage(right, voyage, ind, end, res);
        }
        else {
            res.erase(res.begin(), res.end());
            res.push_back(-1);
        }
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res;
        flipVoyage(root, voyage, 0, voyage.size(), res);
        return res;
    }
};