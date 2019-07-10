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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* odd_head = head;
        ListNode* even_head = head->next;
        ListNode* odd_tail = head;
        ListNode* even_tail = head->next;
        ListNode* p = head->next->next;
        bool isodd = true;
        while(p != NULL) {
            if(isodd) {
                odd_tail->next = p;
                odd_tail = p;
            }
            else {
                even_tail->next = p;
                even_tail = p;
            }
            p = p -> next;
            isodd = !isodd;
        }
        odd_tail -> next = even_head;
        even_tail -> next = NULL;
        return odd_head;
    }
};