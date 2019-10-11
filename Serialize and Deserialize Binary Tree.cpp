/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    TreeNode* newTreeNode(string s) {
        if(s == "NULL")
            return NULL;
        int val = stoi(s);
        return newTreeNode(val);
    }
    TreeNode* newTreeNode(int val) {
        TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
        p->val = val;
        p->left = NULL;
        p->right = NULL;
        return p;
    }
    vector<string> split_s(string s) {
        vector<string> result;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ')
                continue;
            // s[i] != ' '
            for(int j = i+1; j < s.size(); j++) {
                if(s[j] == ' ') {
                    // s[i] to s[j-1]
                    result.push_back(s.substr(i, j-i));
                    i = j;
                    break;
                }
            }
        }
        return result;
    }
    string serialize(TreeNode* root) {
        // BFS
        if(root == NULL) {
            return "";
        }
        queue<TreeNode*> q;
        string result;
        q.push(root);
        while(q.size() > 0) {
            TreeNode* p = q.front();
            q.pop();
            if(p == NULL) {
                result.append("NULL ");
                continue;
            }
            result.append(to_string(p->val));
            result.append(" ");
            q.push(p->left);
            q.push(p->right);
        }
        return result;
    }
    TreeNode* deserialize(string data) {
        vector<string> nodes = split_s(data);
        if(nodes.size() == 0)
            return NULL;
        queue<TreeNode*> q;
        TreeNode* head = NULL;
        for(int i = 0; i < nodes.size(); i++) {
            TreeNode* p = newTreeNode(nodes[i]);
            if(q.size() == 0) {
                // t is head
                head = p;
            }
            else {
                TreeNode* parent;
                parent = q.front();
                q.pop();
                if(q.size() == 0 || q.front() != parent) {
                    parent->right = p;
                }
                else parent->left = p;
            }
            if(p != NULL) {
                q.push(p);
                q.push(p);
            }
        }
        return head;
    }
    /*METHOD3 using preorder and inorder traversal result. But cannot deal with situations when two nodes have identical value*/
    /*
    vector<int> split(string s) {
        vector<int> result;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ')
                continue;
            // s[i] != ' '
            for(int j = i+1; j < s.size(); j++) {
                if(s[j] == ' ') {
                    // s[i] to s[j-1]
                    result.push_back(stoi(s.substr(i, j-i)));
                    i = j;
                    break;
                }
            }
        }
        return result;
    }
    void serialize(TreeNode* root, double root_index, string& result) {
        if(root == NULL)
            return;
        string index = to_string(root_index);
        index.erase(index.find('.'), std::string::npos);
        result.append(index);
        result.append(":");
        result.append(to_string(root->val));
        result.append(" ");
        serialize(root->left, root_index * 2 + 1, result);
        serialize(root->right, root_index * 2 + 2, result); 
    }
    TreeNode* newTreeNode(string s) {
        if(s == "NULL")
            return NULL;
        int val = stoi(s);
        return newTreeNode(val);
    }
    TreeNode* newTreeNode(int val) {
        TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
        p->val = val;
        p->left = NULL;
        p->right = NULL;
        return p;
    }
    string getPreorder(TreeNode* root) {
        if(root == NULL)
            return "";
        string result = to_string(root->val);
        result.append(" ");
        result.append(getPreorder(root->left));
        result.append(getPreorder(root->right));
        return result;
    }
    string getInorder(TreeNode* root) {
        if(root == NULL)
            return "";
        string result = getInorder(root->left);
        result.append(to_string(root->val));
        result.append(" ");
        result.append(getInorder(root->right));
        return result;
    }
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "";
        string preorder = getPreorder(root);
        string inorder = getInorder(root);
        preorder.append("|");
        preorder.append(inorder);
        return preorder;
    }
    TreeNode* constructTree(vector<int>& preorder, int st1, int ed1, vector<int>& inorder, int st2, int ed2) {
        if(st1 > ed1)
            return NULL;
        TreeNode* root = newTreeNode(preorder[st1]);
        int root_index = st2;
        for(; root_index <= ed2; root_index++) {
            if(inorder[root_index] == preorder[st1])
                break;
        }
        if(root_index > ed2)
            return root;
        int left_subTree_size = root_index - st2;
        if(left_subTree_size > 0) {
            TreeNode* left = constructTree(preorder, st1+1, st1+left_subTree_size, inorder, st2, st2+left_subTree_size-1);
            root->left = left;
        }
        TreeNode* right = constructTree(preorder, st1+left_subTree_size+1, ed1, inorder, root_index+1, ed2);
        root->right = right;
        return root;
    }
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return NULL;
        int d = data.find('|');
        string preorder = data.substr(0, d);
        string inorder = data.substr(d+1);
        vector<int> nodes_preorder = split(preorder);
        vector<int> nodes_inorder = split(inorder);
        return constructTree(nodes_preorder, 0, nodes_preorder.size()-1, nodes_inorder, 0, nodes_inorder.size()-1);
    }*/
    /*METHOD2 using index:val pair, but index can be too large*/
    /*string serialize(TreeNode* root) {
        if(root == NULL)
            return "";
        string result;
        serialize(root, 0, result);
        return result;
    }
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return NULL;
        vector<string> nodes = split(data);
        if(nodes.size() == 0)
            return NULL;
        map<double,TreeNode*> m;
        for(int i = 0; i < nodes.size(); i++) {
            int d = nodes[i].find(':');
            int val = stoi(nodes[i].substr(d+1));
            double index = stod(nodes[i].substr(0, d));
            TreeNode* node = newTreeNode(val);
            m.insert(pair<double,TreeNode*>(index, node));
            if(index != 0) {
                double p = round((index-1.5)/2);
                auto iter = m.find(p);
                if(iter == m.end())
                    continue;
                TreeNode* pNode = iter->second;
                if(p*2+1 == index) {
                    // left
                    pNode->left = node;
                }
                else pNode->right = node;
            }
        }
        auto iter = m.find(0);
        if(iter == m.end())
            return NULL;
        return iter->second;
    }*/

    /*METHOD1 exceed memory requirement*/
    // Encodes a tree to a single string.
    /*string serialize(TreeNode* root) {
        // bfs method, storing line-level traversal results
        if(root == NULL)
            return "";
        queue<TreeNode*> q;
        q.push(root);
        int last_node = 0;
        int count = 0;
        string result;
        while(q.size() > 0) {
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) {
                if(count > last_node) {
                    break;
                }
                result.append("NULL ");
                q.push(NULL);
                q.push(NULL);
                count++;
                continue;
            }
            result.append(to_string(node->val));
            result.append(" ");
            if(node->left != NULL)
                last_node = count*2+1;
            if(node->right != NULL)
                last_node = count*2 + 2;
            q.push(node->left);
            q.push(node->right);
            count++;
        }
        return result;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return NULL;
        vector<string> ns = split(data);
        if(ns.size() == 0)
            return NULL;
        vector<TreeNode*> nodes(ns.size(), NULL);
        for(int i = 0; i < nodes.size(); i++)
            nodes[i] = newTreeNode(ns[i]);
        if(nodes[0] == NULL)
            return NULL;
        for(int i = 0; i < nodes.size(); i++) {
            TreeNode* p = nodes[i];
            if(p == NULL)
                continue;
            int left = i * 2 + 1;
            int right = left + 1;
            if(left < nodes.size())
                p->left = nodes[left];
            if(right < nodes.size())
                p->right = nodes[right];
        }
        return nodes[0];
    }*/
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));