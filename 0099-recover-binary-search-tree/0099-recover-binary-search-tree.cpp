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
    TreeNode* prev = nullptr;
    TreeNode* g1first = nullptr;
    TreeNode* g1second = nullptr;
    TreeNode* g2first = nullptr;
    TreeNode* g2second = nullptr;
    int galat = 0;

    void fun(TreeNode* root) {
        if(root == nullptr) return;

        fun(root->left);

        if(prev && prev->val > root->val) {
            if(galat == 0) {
                g1first = prev;
                g1second = root;
                galat++;
            } else {
                g2first = prev;
                g2second = root;
                galat++;
            }
        }
        
        prev = root;
        
        fun(root->right);
    }

    void recoverTree(TreeNode* root) {
        fun(root);

        if(galat == 1) swap(g1first->val, g1second->val);
        else swap(g1first->val, g2second->val);

        return;    
    }
};