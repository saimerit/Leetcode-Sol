/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return NULL;
        queue<TreeNode*> q;
        int ans = root->val;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = n-1; i >=0; i--){
                TreeNode* n = q.front();
                q.pop();
                if(i==0) ans = n->val;
                if(n->right) q.push(n->right);
                if(n->left) q.push(n->left);
            }
        }
        return ans;
    }
};