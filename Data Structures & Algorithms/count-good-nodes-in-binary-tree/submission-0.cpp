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
public:
    int goodNodes(TreeNode* root) {
        int cur_max = -101;
        dfs(root, cur_max);
        return count;
    }
    void dfs(TreeNode* root, int cur_max){
        if(!root){
            return;
        }
        if(root->val >= cur_max){
            count++;
        }
        cur_max = max(cur_max, root->val);
        dfs(root->left, cur_max);
        dfs(root->right, cur_max);
    }
};
