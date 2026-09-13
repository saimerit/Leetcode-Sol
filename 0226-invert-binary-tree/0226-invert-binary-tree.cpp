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
    TreeNode* ff(TreeNode* root){
        if(!root) return NULL;
        TreeNode* nroot = new TreeNode(root->val);
        nroot->left = ff(root->right);
        nroot->right = ff(root->left);
        return nroot;
    }
    TreeNode* invertTree(TreeNode* root) {
        return ff(root);
    }
};