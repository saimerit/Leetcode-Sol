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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        for(int i = 0; i < k; i++){
            if(!curr) return head;
            curr = curr->next;
        }
        ListNode* prev = NULL;
        curr = head;
        ListNode* nex = NULL;
        for(int i = 0; i < k; i++){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        if(nex != NULL) head->next = reverseKGroup(nex, k);
        return prev;
    }
};