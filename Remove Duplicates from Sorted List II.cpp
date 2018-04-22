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
        ListNode* last=NULL;
        for(ListNode* p=head;p->next!=NULL;p=p->next)
        {
            bool delp=false;
            while(p->next!=NULL && p->next->val==p->val)
            {
                delp=true;
                p->next = p->next->next;
            }
            if(delp)
            {
                if(last!=NULL) last->next=p->next;
                else head=p->next;
            }
            else last = p;
            if(p->next==NULL) break;
        }
        return head;
    }
};