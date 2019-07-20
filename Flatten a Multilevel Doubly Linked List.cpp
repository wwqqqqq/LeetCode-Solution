/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten_tail(Node* head) {
        Node* p = head;
        Node* tail = head;
        while(p != NULL) {
            if(p->child == NULL) {
                tail = p;
                p = p->next;
                continue;
            }
            tail = flatten_tail(p->child);
            tail->next = p->next;
            if(p->next != NULL)
                p->next->prev = tail;
            
            p->next = p->child;
            p->next->prev = p;
            p->child = NULL;
            p = tail->next;
        }
        return tail;
    }
    Node* flatten(Node* head) {
        flatten_tail(head);
        return head;
    }
};