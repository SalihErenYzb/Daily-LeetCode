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
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rightSideView2(root,0,ans);
        return ans;
    }
    void rightSideView2(TreeNode* root, int depth, vector<int>& ans) {
        if (root == nullptr) return;
        if (depth == ans.size()) ans.push_back(root->val);
        rightSideView2(root->right,depth+1,ans);
        rightSideView2(root->left,depth+1,ans);
    }
};