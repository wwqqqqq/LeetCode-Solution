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
    ListNode* getMiddleNode(ListNode* head, int len) {
        ListNode* p = head;
        for(int i = 0; i < (len-1)/2; i++) {
            p = p->next;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode* p = head;
        while(p != NULL) {
            len++;
            p = p->next;
        }
        if(len <= 1)
            return true;
        ListNode* mid1 = getMiddleNode(head, len);
        ListNode* mid2 = mid1;
        if(len % 2 == 0) {
            mid2 = mid2->next;
        }
        else {
            mid2 = mid1->next;
            p = head;
            while(p != NULL) {
                if(p->next == mid1) {
                    mid1 = p;
                    break;
                }
                p = p->next;
            }
        }
        p = head;
        ListNode* prev = NULL;
        while(p != NULL) {
            ListNode* next = p->next;
            p->next = prev;
            if(p == mid1)
                break;
            prev = p;
            p = next;

        }
        while(mid1 != NULL && mid2 != NULL) {
            if(mid1->val != mid2->val)
                return false;
            mid1 = mid1->next;
            mid2 = mid2->next;
        }
        return true;
    }
};