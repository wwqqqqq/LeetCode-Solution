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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> s;
        ListNode* p = headA;
        while(p != NULL) {
            if(s.find(p) != s.end())
                break;
            s.insert(p);
            p = p->next;
        }
        set<ListNode*> sb;
        p = headB;
        while(p != NULL) {
            if(sb.find(p) != sb.end())
                break;
            if(s.find(p) != s.end())
                return p;
            sb.insert(p);
            p = p->next;
        }
        return NULL;
    }
};