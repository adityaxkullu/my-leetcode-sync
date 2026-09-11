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
    int idx = 0;

    TreeNode* fun(vector<int> &preorder, int low, int high) {
        if(low > high) return nullptr;

        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;

        int id = inodr[root->val];

        root->left = fun(preorder, low, id - 1);
        root->right = fun(preorder, id + 1, high);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            inodr[inorder[i]] = i;
        }

        return fun(preorder, 0, inorder.size() - 1); 
    }
};