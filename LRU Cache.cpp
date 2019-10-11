class LRUCache {
public:
    typedef struct node{
        int key;
        int val;
        struct node* prev;
        struct node* next;
    }Node;
    Node* newNode(int key, int val) {
        Node* p = (Node*)malloc(sizeof(Node));
        p->key = key;
        p->val = val;
        p->prev = p;
        p->next = p;
        return p;
    }
    Node* head;
    Node* tail;
    int count;
    int maxlen;
    map<int,Node*> m;
    LRUCache(int capacity) {
        maxlen = capacity;
        count = 0;
        tail = NULL;
        head = NULL;
    }
    int get(int key) {
        if(maxlen == 0 || count == 0)
            return -1;
        auto iter = m.find(key);
        if(iter == m.end()) {
            return -1;
        }
        Node* p = iter->second;
        if(p->next == p)
            return p->val;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        if(p == tail)
            tail = p->prev;
        if(p == head)
            head = p->next;
        p->next = head;
        head->prev = p;
        p->prev = tail;
        tail->next = p;
        tail = p;
        return p->val;
    }
    
    void put(int key, int value) {
        if(maxlen == 0)
            return;
        auto iter = m.find(key);
        if(iter != m.end()) {
            iter->second->val = value;
            get(key);
            return;
        }
        if(count == maxlen) {
            // have to delete the first node
            Node* p = head;
            m.erase(p->key);
            p->key = key;
            p->val = value;
            head = p->next;
            tail = p;
            m.insert(pair<int,Node*>(key, p));
            return;
        }
        Node* p = newNode(key, value);
        if(head == NULL) {
            head = p;
            tail = p;
        }
        else {
            tail->next = p;
            p->prev = tail;
            head->prev = p;
            p->next = head;
            tail = p;
        }
        m.insert(pair<int,Node*>(key, p));
        count++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */