class Trie {
public:
    typedef struct Node{
        int val;
        struct Node* children[26];
    }TrieNode; 
    /** Initialize your data structure here. */
    void initNode(TrieNode* node) {
        for(int i = 0; i < 26; i++)
            node->children[i] = NULL;
        node->val = 0;
    }
    TrieNode* root;
    Trie() {
        root = (TrieNode*)malloc(sizeof(TrieNode));
        initNode(root);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            if(p->children[ind] == NULL) {
                TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
                initNode(node);
                p->children[ind] = node;
            }
            p = p->children[ind];
        }
        p->val = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            if(p->children[ind] == NULL)
                return false;
            p = p->children[ind];
        }
        if(p->val == 0)
            return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(int i = 0; i < prefix.size(); i++) {
            int ind = prefix[i] - 'a';
            if(p->children[ind] == NULL)
                return false;
            p = p->children[ind];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */