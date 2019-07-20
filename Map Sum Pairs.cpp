class MapSum {
public:
    /** Initialize your data structure here. */
    typedef struct node {
        int val;
        int sum;
        struct node * (kids[26]);
    } TNode;
    TNode* root;
    
    TNode* newNode() {
        TNode* p = (TNode*)malloc(sizeof(TNode));
        p->val = 0;
        p->sum = 0;
        for(int i = 0; i < 26; i++)
            p->kids[i] = NULL;
        return p;
    }
    
    MapSum() {
        root = newNode();
    }
    
    void insert(string key, int value) {
        stack<TNode*> visited;
        TNode* p = root;
        bool overriden = false;
        int last = 0;
        for(int i = 0; i < key.size(); i++) {
            TNode* child = p->kids[key[i]-'a'];
            if(child == NULL) {
                p->kids[key[i]-'a'] = newNode();
                child = p->kids[key[i]-'a'];
            }
            else {
                int ind = key[i] - 'a';
                if(i == key.size()-1) {
                    overriden = true;
                    last = child->val;
                }
            }
            p->sum = p->sum + value;
            visited.push(p);
            p = child;
        }
        p->val = value;
        p->sum = p->sum - last + value;
        if(overriden) {
            while(visited.size() > 0) {
                TNode* node = visited.top();
                visited.pop();
                node->sum = node->sum - last;
            }
        }
        while(visited.size()>0)
            visited.pop();
    }
    
    int sum(string prefix) {
        TNode* p = root;
        for(int i = 0; i < prefix.size(); i++) {
            p = p->kids[prefix[i]-'a'];
            if(p == NULL)
                return 0;
        }
        return p->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */