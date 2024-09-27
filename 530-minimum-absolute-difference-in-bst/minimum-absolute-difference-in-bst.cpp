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
    int ans = INT_MAX;
    int getMinimumDifference(TreeNode* root, 
    TreeNode* minN = nullptr,TreeNode* maxN = nullptr) {
        if (root == nullptr) return INT_MAX;
        if (minN && ans > abs(root->val-minN->val)){
            ans = abs(root->val-minN->val);
        }
        if (maxN && ans > abs(root->val-maxN->val)){
            ans = abs(root->val-maxN->val);
        }
        getMinimumDifference(root->left,minN,root);
        getMinimumDifference(root->right,root,maxN);
        return ans;
    }
};