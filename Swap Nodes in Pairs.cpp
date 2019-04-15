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
    ListNode* swapPairs(ListNode* head) {
        ListNode* newhead = NULL;
        ListNode* p = NULL;
        ListNode* last = NULL;

        while(head != NULL) {
            last = head;
            if(head->next == NULL) {
                if(p == NULL)
                    newhead = head;
                else
                    p->next = head;
                return newhead;
            }
            head = head->next;
            if(p != NULL)
                p->next = head;
            p = head;
            head = head->next;
            p->next = last;
            if(newhead == NULL)
                newhead = p;
            p = p->next;
        }
        if(p != NULL)
            p->next = NULL;
        return newhead;
    }
};