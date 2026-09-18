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
    void f(TreeNode* root, int& ans, int l){
        if(!root->left && !root->right){
            ans = max(l, ans);
            return;
        }
        if(root->left) f(root->left, ans, l+1);
        if(root->right) f(root->right, ans, l+1);
    }
    void fill(TreeNode* root, vector<vector<string>>& mat, int i, int l, int r){
        if(!root) return;
        
        int mid = l + (r - l) / 2;
        mat[i][mid] = to_string(root->val);
        fill(root->left, mat, i+1, l, mid - 1);
        fill(root->right, mat, i+1, mid + 1, r);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        if(!root) return {};
        int ma_h = 0;
        f(root, ma_h, 1);
        int c = pow(2, ma_h) - 1;
        vector<vector<string>> mat(ma_h, vector<string>(c, ""));
        fill(root, mat, 0, 0, c);
        return mat;
    }
};