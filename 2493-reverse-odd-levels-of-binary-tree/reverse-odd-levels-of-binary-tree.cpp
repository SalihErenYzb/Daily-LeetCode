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
    void helper(TreeNode* nodeleft, TreeNode* noderight, int depth){
        if (!nodeleft) return;
        if (depth%2){
            int tmp = nodeleft->val;
            nodeleft->val = noderight->val;
            noderight->val = tmp;
        }
        helper(nodeleft->left, noderight->right,depth+1);
        helper(nodeleft->right, noderight->left,depth+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root || !root->left) return root;
        helper(root->left, root->right, 1);
        return root;
    }
};