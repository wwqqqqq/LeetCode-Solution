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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(p1 != NULL && p2 != NULL) {
            if(p1->val < p2->val) {
                if(head == NULL) {
                    head = p1;
                    tail = p1;
                }
                else {
                    tail->next = p1;
                    tail = p1;
                }
                p1 = p1->next;
            }
            else {
                if(head == NULL) {
                    head = p2;
                    tail = p2;
                }
                else {
                    tail->next = p2;
                    tail = p2;
                }
                p2 = p2->next;
            }
        }
        if(p1 != NULL) {
            if(head == NULL)
                return l1;
            else tail->next = p1;
        }
        if(p2 != NULL) {
            if(head == NULL)
                return l2;
            else tail->next = p2;
        }
        return head;
    }
};