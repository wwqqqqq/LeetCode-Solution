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
    ListNode* merge(vector<ListNode*>::iterator beg, vector<ListNode*>::iterator ed)
    {
        int size=ed-beg;
        if(size<=0) return NULL;
        if(size==1) return *beg;
        
        ListNode *p1 = merge(beg, beg+size/2);
        ListNode *p2 = merge(beg+size/2,ed);
        
        ListNode *p;
        if(p1==NULL) return p2;
        else if(p2==NULL) return p1;
        if(p1->val<=p2->val)
        {
            p = p1;
            p1 = p1->next;
        }
        else
        {
            p = p2;
            p2 = p2->next;
        }
        ListNode *res=p;
        while(p1!=NULL && p2!=NULL)
        {
            if(p1->val<=p2->val)
            {
                p->next = p1;
                p = p->next;
                p1 = p1->next;
            }
            else
            {
                p->next = p2;
                p = p->next;
                p2 = p2->next;
            }
        }
        if(p1!=NULL) p->next = p1;
        else if(p2!=NULL) p->next = p2;
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==1) return lists[0];
        else if(lists.size()<1) return NULL;
        return merge(lists.begin(),lists.end());
    }
};