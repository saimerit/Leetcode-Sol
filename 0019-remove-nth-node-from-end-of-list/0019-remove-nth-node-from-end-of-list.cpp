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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* d = new ListNode(0);
        d->next = head;

        ListNode* first = d;
        ListNode* second = d;
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        ListNode* nodeToDelete = second->next;
        second->next = nodeToDelete->next;
        ListNode* newHead = d->next;
        delete d;  
        return newHead;
    }
};