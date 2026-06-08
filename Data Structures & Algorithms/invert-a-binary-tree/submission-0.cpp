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
    void swapNode(TreeNode* a, TreeNode* b){
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        traverse(root);
        return root;
    }
    void traverse(TreeNode* root){
        if(!root){
            return;
        }
        traverse(root->left);
        traverse(root->right);
        swap(root->left, root->right);
        return;
    }
};
