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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return {-1, -1}; 
        vector<int> vals;
        ListNode* temp = head;
        while(temp != NULL){
            vals.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> crit;
        int n = vals.size();
        for(int i = 1; i < n-1; i++){
            if((vals[i-1] < vals[i] && vals[i] > vals[i+1]) || (vals[i-1] > vals[i] && vals[i] < vals[i+1])) crit.push_back(i);
        }
        if(crit.size() < 2) return {-1, -1};
        int mind = INT_MAX;
        int maxd = crit[crit.size()-1] - crit[0];
        for(int i = 1; i < crit.size(); i++){
            mind = min(mind, crit[i] - crit[i-1]);
        }
        return {mind, maxd};
    }
};