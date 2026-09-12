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
    unordered_map<int, int> posodr;
    int idx = 0;

    TreeNode* fun(vector<int> &postorder, vector<int> &preorder, int low, int high) {
        if(low > high) return nullptr;

        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;

        if(low == high) return root;

        int id = posodr[preorder[idx]];

        root->left = fun(postorder, preorder, low, id);
        root->right = fun(postorder, preorder, id + 1, high - 1);

        return root;    
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i = 0; i < postorder.size(); i++) {
            posodr[postorder[i]] = i;
        }

        return fun(postorder, preorder, 0, postorder.size() - 1);    
    }
};