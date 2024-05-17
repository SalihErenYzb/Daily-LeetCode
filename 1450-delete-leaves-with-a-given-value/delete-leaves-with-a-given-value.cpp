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
    TreeNode* removeLeafNodes(TreeNode* node, int tar) {
        if (node == nullptr) return nullptr;
        node->right = removeLeafNodes(node->right,tar);
        node->left = removeLeafNodes(node->left,tar);
        if (node->right == nullptr && node->left == nullptr && node->val == tar){
            return nullptr;
        }
        return node;
    }


};