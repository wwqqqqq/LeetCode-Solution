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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        ListNode* p = head;
        while(p != NULL) {
            nodes.push_back(p);
            p = p->next;
        }
        if(nodes.size() < n || n == 0)
            return head;
        if(nodes.size() == n)
            return head->next;
        if(n == 1) {
            nodes[nodes.size() - 2]->next = NULL;
            return head;
        }
        nodes[nodes.size() - 1 - n]->next = nodes[nodes.size() + 1 - n];
        return head;
    }
};