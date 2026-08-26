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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* h1 = NULL;
        ListNode* temp = head;
        while(temp != NULL){
            ListNode* newN = new ListNode(temp->val);
            if(h1== NULL){
                h1 = newN;
                newN->next = NULL;
            }else{
                newN->next = h1;
                h1 = newN;
            }
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            if(h1->val != temp->val)return false;
            temp = temp->next;
            h1 = h1->next;
        }
        return true;
    }
};