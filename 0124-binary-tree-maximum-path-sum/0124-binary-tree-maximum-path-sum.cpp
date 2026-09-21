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
        int temp = max(max(l,r) + root->val, root->val);
        int ans = max(temp, l+r+root->val);
        res = max(ans, res);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int t = f(root, ans);
        return ans;
    }
};