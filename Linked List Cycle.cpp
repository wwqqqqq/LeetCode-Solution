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
    bool hasCycle(ListNode *head) {
        //vector<ListNode *> visited;
        //vector<ListNode *>::iterator it;
        set<ListNode *> visited;
        ListNode *p = head;
        while(p != NULL)
        { 
            //for(it=visited.begin();it!=visited.end();it++)
            //    if(*it == p)
            //        return true;
            //visited.push_back(p);
            
            if(visited.find(p) != visited.end())
                return true;
            visited.insert(p);
            p = p->next;
        }
        return false;
    }
};