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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode* dum = new ListNode(0);
        dum->next = head;
        ListNode* curr = dum;
        while(curr->next != NULL && curr->next->next != NULL){
            if(curr->next->val == curr->next->next->val){
                int dup = curr->next->val;
                while(curr->next && curr->next->val == dup){
                    ListNode* t = curr->next;
                    curr->next = curr->next->next;
                    delete t;
                }
            }else{
                curr= curr->next;
            }
        }
        ListNode* newHead = dum->next;
        delete dum;
        return newHead;
    }
};