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
    vector<int> fun(TreeNode* root, vector<int> &res) {
        if(root == nullptr) return res;

        fun(root->left, res);

        res.push_back(root->val);
        fun(root->right, res);

        return res;
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        fun(root, res);

        int n = res.size();

        for(int i = 1; i < n; i++) {
            if(res[i] <= res[i - 1]) return false;
        }

        return true;
    }
};