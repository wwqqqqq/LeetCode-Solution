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
    void reorderList(ListNode* head) {
        if(head==NULL) return;
        vector<ListNode*> vec;
        for(ListNode* p=head;p!=NULL;p=p->next) vec.push_back(p);
        auto iter1=vec.begin()+1;
        auto iter2=vec.end()-1;
        ListNode* p=head;
        while(iter1<iter2)
        {
            p->next=*iter2;
            p=p->next;
            iter2=iter2-1;
            p->next=*iter1;
            p=p->next;
            iter1=iter1+1;
        }
        if(iter1==iter2)
        {
            p->next=*iter1;
            p=p->next;
        }
        p->next=NULL;
    }
};