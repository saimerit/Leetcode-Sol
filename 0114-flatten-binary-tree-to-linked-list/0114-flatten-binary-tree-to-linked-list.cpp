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
    void f(TreeNode* root, vector<TreeNode*>& st){
        if(!root) return;
        st.push_back(root);
        if(root->left) f(root->left, st);
        if(root->right) f(root->right, st);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> preOrd;
        f(root, preOrd);
        int n = preOrd.size();
        for(int i = 0; i < n-1; i++){
            preOrd[i]->left = NULL;
            preOrd[i]->right = preOrd[i+1];
        }
    }
};