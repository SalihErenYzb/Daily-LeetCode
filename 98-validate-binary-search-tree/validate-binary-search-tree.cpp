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
    bool dfs(TreeNode* node, long min = INT_MIN, long max = INT_MAX){
        if (node == nullptr) return true;
        if (node->val > max || node->val < min){
            return false;
        }
        if (!dfs(node->right,node->val+1ll,max)) return false;
        if (!dfs(node->left,min,node->val-1ll)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root);
    }
};