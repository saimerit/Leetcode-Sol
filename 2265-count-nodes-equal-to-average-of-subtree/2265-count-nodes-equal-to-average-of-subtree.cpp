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
    vector<int> bt(TreeNode* root, int& res){
        if(!root) return {0, 0};
        vector<int> l = bt(root->left, res);
        vector<int> r = bt(root->right, res);
        int nval = l[0] + r[0] + root->val;
        int ncnt = l[1] + r[1] + 1;
        if (nval/ncnt == root->val) res++;
        return {nval, ncnt};
    }
    int solve(TreeNode* root){
        int ans = 0;
        vector<int> op = bt(root, ans);
        return ans;
    }
    int averageOfSubtree(TreeNode* root) {
        return solve(root);
    }
};