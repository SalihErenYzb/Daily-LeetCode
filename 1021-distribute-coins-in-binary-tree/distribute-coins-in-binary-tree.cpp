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
    int distributeCoins(TreeNode* root) {

        int ans = 0;
        dfs(root,ans);
        return ans;
    }
    int dfs(TreeNode* node,int& ans){
        int curr = -1+node->val;
        int tmp;
        if (node->left != nullptr){ 
            tmp = dfs(node->left,ans);
            curr += tmp;
            ans += abs(tmp);
        }
        if (node->right != nullptr){
            tmp = dfs(node->right,ans);
            curr += tmp;
            ans += abs(tmp);
        }
        return curr;
    }
};