/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        int n = 1;
        ListNode* t = head;
        while(t->next != NULL) {
            t= t->next;
            n++;
        }
        t->next = head;
        int st = n -  (k%n);
        ListNode* nt = head;
        for(int i = 1; i < st; i++) nt = nt->next;
        ListNode* nhead = nt->next;
        nt->next = NULL;
        return nhead;
    }
};