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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root==NULL) return res;
        if(root->left==NULL && root->right==NULL)
        {
            ostringstream ostr;
            ostr<<root->val;  
            string str = ostr.str();  
            res.push_back(str);
            return res;
        }
        ostringstream ostr;
        ostr<<root->val<<"->";
        string s1 = ostr.str();
        if(root->left!=NULL)
        {
            vector<string> vec=binaryTreePaths(root->left);
            for(auto iter=vec.begin();iter<vec.end();iter++)
            {
                auto s2=*iter;
                auto s=s1+s2;
                res.push_back(s);
            }
        }
        if(root->right!=NULL)
        {
            vector<string> vec=binaryTreePaths(root->right);
            for(auto iter=vec.begin();iter<vec.end();iter++)
            {
                auto s2=*iter;
                s2=s1+s2;
                res.push_back(s2);
            }
        }
        return res;
    }
};