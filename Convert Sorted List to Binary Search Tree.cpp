/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* insertBST(ListNode *head, ListNode *tail, int len)
    {
        ListNode *p;
        int i;
        if(len<1) return NULL;
        TreeNode *root=(TreeNode*)malloc(sizeof(TreeNode));
        if(head==tail)
        {
            root->left=NULL;
            root->right=NULL;
            root->val=head->val;
            return root;
        }
        for(i=1,p=head;i<len/2;i++)
            p=p->next;
        root->left=insertBST(head, p, i);
        p = p->next;
        root->val = p->val;
        p = p->next;
        root->right=insertBST(p, tail, len-i-1);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* p;
        int count=1;
        for(p=head;p->next!=NULL;p=p->next) count++;
        return insertBST(head, p, count);
    }
};