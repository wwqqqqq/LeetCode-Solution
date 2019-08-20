class Solution {
public:
    typedef struct node {
        bool complete;
        struct node* (kids[26]);
    } Node;
    Node* newnode(bool complete) {
        Node* p = (Node*)malloc(sizeof(Node));
        p->complete = complete;
        for(int i = 0; i < 26; i++)
            p->kids[i] = NULL;
        return p;
    }
    void insert(Node* root, string s) {
        Node* p = root;
        for(int i = 0; i < s.size(); i++) {
            int ind = s[i] - 'a';
            if(p->kids[ind] == NULL) {
                Node* q = newnode(false);
                p->kids[ind] = q;
            }
            p = p->kids[ind];
        }
        p->complete = true;
    }
    int consist(Node* root, string s) {
        if(s.size() == 0)
            return 0;
        Node* p = root;
        for(int i = 0; i < s.size(); i++) {
            int ind = s[i] - 'a';
            if(p->kids[ind] == NULL)
                return -1;
            p = p->kids[ind];
            if(p->complete) {
                if(i == s.size()-1)
                    return 1;
                else {
                    int c = consist(root, s.substr(i+1));
                    if(c >= 0)
                        return c + 1;
                }
            }
        }
        return -1;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Node* root = newnode(false);
        for(int i = 0; i < words.size(); i++)
            insert(root, words[i]);
        vector<string> result;
        for(int i = 0; i < words.size(); i++) {
            if(consist(root, words[i]) > 1)
                result.push_back(words[i]);
        }
        return result;
    }
};