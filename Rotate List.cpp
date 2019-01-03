/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int size = 0;
        ListNode* p = head;
        ListNode* q = head;
        while(p != NULL) {
            size++;
            q = p;
            p = p -> next;
        }
        if(size <= 1)
            return head;
        // now q is the tail node
        k = k % size;
        if(k == 0)
            return head;
        q -> next = head;
        p = head;
        for(int i = 0; i < size - k; i++) {
            q = p;
            p = p -> next;
        }
        q -> next = NULL;
        return p;
    }
};