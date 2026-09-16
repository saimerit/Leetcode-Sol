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
    void f(TreeNode* root, int tsum, vector<vector<int>>& ans, vector<int>& path, int s){
        if(!root->left && !root->right && (s + root->val == tsum)){
            path.push_back(root->val);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        if(root->left){
            f(root->left, tsum, ans, path, s+root->val);
        }
        if(root->right){
            f(root->right, tsum, ans, path, s+root->val);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<vector<int>> ans;
        vector<int> path;
        f(root, targetSum, ans, path, 0);
        return ans;
    }
};