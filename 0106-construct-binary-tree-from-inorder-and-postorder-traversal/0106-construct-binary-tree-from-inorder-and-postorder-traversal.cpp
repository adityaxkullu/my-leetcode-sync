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
    unordered_map<int, int> inodr;
    int idx;

    TreeNode* fun(vector<int> postorder, int low, int high) {
        if(low > high) return nullptr;

        TreeNode* root = new TreeNode(postorder[idx]);
        idx--;

        int id = inodr[root->val];

        root->right = fun(postorder, id + 1, high);
        root->left = fun(postorder, low, id - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++) inodr[inorder[i]] = i;

        idx = postorder.size() - 1;

        return fun(postorder, 0, inorder.size() - 1);    
    }
};