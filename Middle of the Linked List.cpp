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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        if(fast != NULL) fast = fast->next;
        else return NULL;
        if(fast == NULL)
            return slow;
        while(true) {
            fast = fast->next;
            if(fast != NULL)
                fast = fast->next;
            else break;
            if(fast == NULL)
                break;
            slow = slow->next;
        }
        if(slow != NULL)
            return slow->next;
        return NULL;
    }
};