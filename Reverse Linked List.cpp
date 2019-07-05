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
    ListNode* reverseList(ListNode* head) {
        ListNode* last = NULL;
        ListNode* p = head;
        while(p != NULL) {
            ListNode* next = p->next;
            p->next = last;
            last = p;
            p = next;
        }
        return last;
        /*stack<ListNode*> s;
        while(head != NULL) {
            s.push(head);
            head = head -> next;
        }
        if(s.size() == 0)
            return NULL;
        head = s.top();
        s.pop();
        ListNode* p = head;
        while(s.size() > 0) {
            p -> next = s.top();
            p = s.top();
            s.pop();
        }
        p -> next = NULL;
        return head;*/
    }
};