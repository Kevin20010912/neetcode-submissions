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
    int count = 0;
    int res;
public:
    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k);
        return res;
    }
    void traverse(TreeNode* root, int k){
        if(!root){
            return;
        }
        if(count >= k){
            return;
        }
        traverse(root->left, k);
        count++;
        if(count == k){
            res = root->val;
        }
        traverse(root->right, k);
        return;
    }
};
