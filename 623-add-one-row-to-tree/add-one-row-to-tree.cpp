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
 #pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1){
            return new TreeNode(val,root,nullptr);
        }
        dfs(root,depth,val);
        return root;
    }
    void dfs(TreeNode*& node,int depth,int& val){
        if (node == nullptr){return;}
        if (depth == 2){
            node->left = new TreeNode(val,node->left,nullptr);
            node->right = new TreeNode(val,nullptr,node->right);
            return;
        }
        dfs(node->left,--depth,val);
        dfs(node->right,depth,val);
    }
};