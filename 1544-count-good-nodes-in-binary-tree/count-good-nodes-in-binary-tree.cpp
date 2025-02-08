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
    int goodNodes(TreeNode* root, int maxim = INT_MIN) {
        if (root == nullptr) return 0;
        int ans = 0;
        if (root->val >= maxim){
            ans++;
            maxim = root->val;
        }
        ans += goodNodes(root->left, maxim) + goodNodes(root->right, maxim);
        return ans;
    }
};