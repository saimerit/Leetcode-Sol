/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*, Node*> cl;
        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        cl[head] = newHead;
        while(oldTemp != NULL){
            Node* t = new Node(oldTemp->val);
            cl[oldTemp] = t;
            newTemp->next = t;
            oldTemp = oldTemp->next;
            newTemp = t;
        }
        Node* temp = head;
        Node* temp2 = newHead;
        while(temp != NULL){
            temp2->random = cl[temp->random];
            temp = temp->next;
            temp2 = temp2->next;
        }
        return newHead;
    }
};