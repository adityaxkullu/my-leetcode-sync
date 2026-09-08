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
    void solve(TreeNode* root, vector<int> &path, vector<vector<int>> &ans, int target) {
        if(root == nullptr) return;
        
        path.push_back(root->val);
        target = target - root->val;

        if(root->left == nullptr && root->right == nullptr) {
            if(target == 0) {
                ans.push_back(path);
            }

            path.pop_back();
            return;
        }

        solve(root->left, path, ans, target);
        solve(root->right, path, ans, target);

        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        solve(root, path, ans, targetSum);
        return ans;    
    }
};