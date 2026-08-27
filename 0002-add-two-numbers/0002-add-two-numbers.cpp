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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        int carry = 0;

        ListNode* mover1 = l1;
        ListNode* mover2 = l2;

        while (mover1 != nullptr || mover2 != nullptr || carry != 0) {
            int sum = carry; 
            if (mover1 != nullptr) {
                sum += mover1->val; 
                mover1 = mover1->next;
            }
            if (mover2 != nullptr) {
                sum += mover2->val; 
                mover2 = mover2->next;
            }
        
            carry = sum / 10; 
            temp->next = new ListNode(sum % 10); 
            temp = temp->next;         
        }

        return head->next;
    }
};