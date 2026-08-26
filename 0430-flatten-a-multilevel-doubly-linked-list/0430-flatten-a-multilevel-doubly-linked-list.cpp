/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void bInc(Node* &t, Node* &c){
        if(t == NULL) return;
        while(t != NULL){
            Node* newNode = new Node();
            newNode->val = t->val;
            c->next = newNode;
            c->next->prev = c;
            c = newNode;
            if(t->child != NULL){
                bInc(t->child, c);
            }
            t = t->next;
        }
    }
    Node* flatten(Node* head) {
        if(head == NULL) return NULL;
        Node* h = new Node();
        h->val = head->val;
        Node* curr = h;
        Node* temp = head;
        while(temp != NULL){
            Node* newNode = new Node();
            newNode->val = temp->val;
            curr->next = newNode;
            curr->next->prev = curr;
            curr = newNode;
            if(temp->child != NULL){
                bInc(temp->child, curr);
            }
            temp = temp->next;
        }
        Node* tk = h;
        h = h->next;
        h->prev = NULL;
        tk->next = NULL;
        delete tk; 
        return h;
    }
};