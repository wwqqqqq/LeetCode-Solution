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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        for(ListNode* p=head;p->next!=NULL;p=p->next)
        {
            while(p->next!=NULL && p->next->val==p->val)
            {
                p->next = p->next->next;
            }
            if(p->next==NULL) break;
        }
        return head;
    }
};