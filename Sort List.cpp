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
    // merge sort
    ListNode* merge(ListNode* h1, ListNode* h2) {
        // merge two sorted list
        ListNode* head = NULL;
        ListNode* tail = NULL;
        ListNode* p1 = h1;
        ListNode* p2 = h2;
        while(p1 != NULL && p2 != NULL) {
            if(p1->val < p2->val) {
                // use p1
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
                // use p2
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
        if(p1 == NULL)
            tail->next = p2;
        else tail->next = p1;
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        // find the middle node
        ListNode* fast = head;
        ListNode* slow = head;
        fast = fast->next;
        while(true) {
            fast = fast->next;
            if(fast != NULL)
                fast = fast->next;
            else break;
            if(fast == NULL)
                break;
            slow = slow->next;
        }
        ListNode* middle = slow->next;
        slow->next = NULL;
        head = sortList(head);
        middle = sortList(middle);
        return merge(head, middle);
    }
};