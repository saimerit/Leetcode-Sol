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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return nullptr;
        ListNode* head1 = NULL;
        ListNode* temp = head;
        while(temp != NULL){
            ListNode* t = new ListNode(temp->val);
            t->next = head1;
            head1 = t;
            temp = temp->next;
        }
        return head1;
    }
};