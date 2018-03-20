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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto p1 = l1;
        auto p2 = l2;
        int size1=0,size2=0;
        for(;p1!=NULL;p1=p1->next) size1++;
        for(;p2!=NULL;p2=p2->next) size2++;
        int carry=0;
        ListNode *result;
        if(size1>=size2)
        {
            result = l1;
            p1 = l1;
            p2 = l2;
        }
        else
        {
            result = l2;
            p1 = l2;
            p2 = l1;
        }
        ListNode * p;
        while(p2!=NULL)
        {
            int res = carry + p1->val + p2->val;
            carry = res / 10;
            p1->val = res % 10;
            p = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        while(carry!=0)
        {
            if(p1!=NULL)
            {
                int res = p1->val+carry;
                carry=res/10;
                p1->val = res%10;
                p=p1;
                p1=p1->next;
            }
            else
            {
                p1 = (ListNode*)malloc(sizeof(ListNode));
                p->next = p1;
                p1->val = carry;
                carry = 0;
                p1->next = NULL;
            }
        }
        
        return result;
    }
};