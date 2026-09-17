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
    void f(TreeNode* root, int val, int n, int depth){
        if(n+1 == depth){
            TreeNode* leftN = new TreeNode(val, root->left, NULL);
            TreeNode* rightN = new TreeNode(val, NULL, root->right);
            root->left = leftN;
            root->right = rightN;
            return;
        }
        if(root->left) f(root->left, val, n+1, depth);
        if(root->right) f(root->right, val, n+1, depth);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root && depth != 1) return NULL;
        if(depth == 1){
            TreeNode* leftN = new TreeNode(val, root, NULL);
            return leftN;
        }
        f(root, val, 1, depth);
        return root;
    }
};