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
    bool flag = true;
public:
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return flag;
    }
    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        if(!flag){
            return 0;
        }
        int left_hi = dfs(root->left);
        int right_hi = dfs(root->right);

        if(abs(left_hi - right_hi) > 1){
            flag = false;
        }
        return max(left_hi, right_hi) + 1;
    }
};
