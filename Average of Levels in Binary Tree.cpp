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
    vector<pair<double,int>> sumoflevels(TreeNode* root) {
        if(root == NULL) {
            vector<pair<double,int>> result;
            return result;
        }
        if(root->left == NULL && root->right == NULL) {
            vector<pair<double,int>> result;
            result.push_back(pair<double,int>(root->val, 1));
            return result;
        }
        else if(root->left == NULL) {
            vector<pair<double,int>> rtree = sumoflevels(root->right);
            rtree.insert(rtree.begin(), pair<double,int>(root->val, 1));
            return rtree;
        }
        else if(root->right == NULL) {
            vector<pair<double,int>> ltree = sumoflevels(root->left);
            ltree.insert(ltree.begin(), pair<double,int>(root->val, 1));
            return ltree;
        }
        vector<pair<double,int>> ltree = sumoflevels(root->left);
        vector<pair<double,int>> rtree = sumoflevels(root->right);
        for(int i = 0; i < ltree.size() && i < rtree.size(); i++) {
            ltree[i].first = ltree[i].first + rtree[i].first;
            ltree[i].second = ltree[i].second + rtree[i].second;
        }
        if(rtree.size() > ltree.size()) {
            ltree.insert(ltree.end(), rtree.begin() + ltree.size(), rtree.end());
        }
        ltree.insert(ltree.begin(), pair<double,int>(root->val, 1));
        return ltree;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<pair<double,int>> sums = sumoflevels(root);
        vector<double> result(sums.size(), 0);
        for(int i = 0; i < sums.size(); i++) {
            double aver = sums[i].first / sums[i].second;
            result[i] = aver;
        }
        return result;
    }
};