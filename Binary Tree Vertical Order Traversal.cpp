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
    int find(vector<int>& array, int e) {
        int beg = 0;
        int end = array.size()-1;
        while(beg < end) {
            int mid = (beg + end) / 2;
            if(array[mid] == e)
                return mid;
            else if(array[mid] < e)
                beg = mid+1;
            else end = mid-1;
        }
        return beg;
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<int> index;
        vector<vector<int>> result;
        queue<TreeNode*> nodes;
        queue<int> nodeIndex;
        nodes.push(root);
        nodeIndex.push(0);
        while(nodes.size() > 0) {
            TreeNode* p = nodes.front();
            int i = nodeIndex.front();
            nodes.pop();
            nodeIndex.pop();
            if(p == NULL)
                continue;
            if(index.size() == 0 || i > index[index.size()-1]) {
                index.push_back(i);
                vector<int> temp = {p->val};
                result.push_back(temp);
            }
            else if(i < index[0]) {
                index.insert(index.begin(), i);
                vector<int> temp = {p->val};
                result.insert(result.begin(), temp);
            }
            else {
                int col = find(index, i);
                result[col].push_back(p->val);
            }
            nodes.push(p->left);
            nodes.push(p->right);
            nodeIndex.push(i-1);
            nodeIndex.push(i+1);
        }
        return result;
    }
};