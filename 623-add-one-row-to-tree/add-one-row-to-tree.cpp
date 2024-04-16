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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1){
            root = new TreeNode(val,root,nullptr);
            return root;
        }
        dfs(root,1,--depth,val);
        return root;
    }
    void dfs(TreeNode*& node,int dep,int& goal,int& val){
        if (node == nullptr){
            return;
        }
        if (goal == dep){
            node->left = new TreeNode(val,node->left,nullptr);
            node->right = new TreeNode(val,nullptr,node->right);
        }
        dfs(node->left,++dep,goal,val);
        dfs(node->right,dep,goal,val);
    }
};