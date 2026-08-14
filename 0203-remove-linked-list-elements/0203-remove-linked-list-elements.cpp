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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dum = new ListNode();
        dum->next = head;
        ListNode* curr = dum;
        while(curr->next != NULL){
            if(curr->next->val == val){
                ListNode* tod = curr->next;
                curr->next = curr->next->next;
                delete tod;
            }else{
                curr = curr->next;
            }
        }
        ListNode* newHead = dum->next;
        delete dum;
        return newHead;
    }
};