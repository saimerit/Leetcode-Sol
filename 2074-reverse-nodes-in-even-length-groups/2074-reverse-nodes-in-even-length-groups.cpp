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
    ListNode* sol(ListNode* h, int g){
        if(!h) return h;
        ListNode* curr = h;
        int act_len = 0;
        while(curr && act_len < g){
            act_len++;
            curr = curr->next;
        }
        ListNode* ngh = curr;
        ListNode* nph = sol(ngh, g+1);
        if(act_len%2 == 1){
            curr = h;
            for(int i= 0; i < act_len -1; i++) curr = curr->next;
            curr->next= nph;
            return h;
        }
        ListNode* prev = nph;
        curr = h;
        ListNode* nex = NULL;
        for(int i = 0; i < act_len; i++){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        return sol(head, 1);   
    }
};