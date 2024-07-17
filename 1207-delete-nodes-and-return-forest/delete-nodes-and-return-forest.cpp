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
    void dfs(TreeNode*& node,vector<TreeNode*>& ans,unordered_set<int>& s){   
        if (node->right) dfs(node->right,ans,s);
        if (node->left) dfs(node->left,ans,s);
        if (s.find(node->val) != s.end()){
            if (node->right) 
                ans.push_back(node->right);
            if (node->left) 
                ans.push_back(node->left);
            delete node;
            node = nullptr;
        }
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s(begin(to_delete),end(to_delete));
        vector<TreeNode*> ans;
        if (s.find(root->val) == s.end()) ans.push_back(root);
        dfs(root,ans,s);
        return ans;
    }
};