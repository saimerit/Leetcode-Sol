/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int ans = 0;
        queue<pair<Node*, int>> q;
        q.push({root, 1});
        while(!q.empty()){
            Node* t = q.front().first;
            int l = q.front().second;
            q.pop();
            ans = max(ans, l);
            for(const auto& c : t->children) q.push({c, l+1});
        }
        return ans;
    }
};