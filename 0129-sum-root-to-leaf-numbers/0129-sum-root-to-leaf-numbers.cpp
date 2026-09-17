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
    void f(TreeNode* root, int& ans, int& p){
        if(!root->left && !root->right){
            p *= 10;
            p += root->val;
            ans += p;
            p /= 10;
            return;
        }
        p *= 10;
        p += root->val;
        if(root->left) f(root->left, ans, p);
        if(root->right) f(root->right, ans, p);
        p /= 10;
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        int p = 0;
        f(root, ans, p);
        return ans;
    }
};