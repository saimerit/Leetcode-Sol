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
    int f(TreeNode* root, int& res){
        if(!root) return 0;
        int l = f(root->left, res);
        int r = f(root->right, res);
        int temp = 1 + max(l, r);
        int ans = max(temp, l+r+1);
        res = max(res, ans);
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        int t = f(root, ans);
        return ans-1;
    }
};