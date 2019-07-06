class StreamChecker {
public:
    typedef struct node {
        bool isEnd;
        struct node* (children[26]);
    } Node;
    Node* root;
    Node* initNode() {
        Node* p = (Node*)malloc(sizeof(Node));
        for(int i = 0; i < 26; i++)
            p->children[i] = NULL;
        p->isEnd = false;
        return p;
    }
    void insertWord(Node* root, string word) {
        if(word.size() == 0)
            return;
        if(root == NULL)
            root = initNode();
        int index = word[0] - 'a';
        if(root->children[index] == NULL) {
            root->children[index] = initNode();
        }
        if(word.size() == 1)
            root->children[index]->isEnd = true;
        else insertWord(root->children[index], word.substr(1));
    }
    vector<Node*> currentNodes;
    StreamChecker(vector<string>& words) {
         root = initNode();
        for(int i = 0; i < words.size(); i++) {
            insertWord(root, words[i]);
        }
    }
    bool query(char letter) {
        int index = letter - 'a';
        bool result = false;
        for(int i = 0; i < currentNodes.size(); i++) {
            Node* p = currentNodes[i];
            if(p->children[index] == NULL) {
                currentNodes.erase(currentNodes.begin()+i);
                i--;
            }
            else {
                currentNodes[i] = p->children[index];
                p = currentNodes[i];
                if(p->isEnd)
                    result = true;
            }
        }
        if(root->children[index] != NULL) {
            Node* p = root->children[index];
            currentNodes.push_back(p);
            if(p->isEnd)
                result = true;
        }
        return result;
    }
    /*vector<string> dict;
    vector<pair<int,int>> points;
    StreamChecker(vector<string>& words) {
        for(int i = 0; i < words.size(); i++) {
            dict.push_back(words[i]);
        }
    }
    
    bool query(char letter) {
        bool result = false;
        for(int i = 0; i < points.size(); i++) {
            string s = dict[points[i].first];
            int ofst = points[i].second;
            if(ofst >= s.size() || s[ofst] != letter) {
                points.erase(points.begin() + i);
                i--;
            }
            else {
                points[i].second += 1;
                if(points[i].second == s.size()) {
                    result = true;
                    points.erase(points.begin() + i);
                    i--;
                }
            }
        }
        for(int i = 0; i < dict.size(); i++) {
            if(dict[i][0] == letter) {
                if(dict[i].size() == 1)
                    result = true;
                else points.push_back(pair<int,int>(i, 1));
            }
        }
        return result;
    }*/
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */