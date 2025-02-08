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
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root, int depth = 0) {
        if (root == nullptr) return {};
        if (depth == ans.size()) ans.push_back(root->val);
        rightSideView(root->right,depth+1);
        rightSideView(root->left,depth+1);
        return ans;
    }
};