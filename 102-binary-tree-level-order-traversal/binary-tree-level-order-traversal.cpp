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
    vector<vector<int>> answer;
    void dfs(TreeNode* node, int depth){
        if (node == nullptr) return;
        // add to answer
        if (answer.size() <= depth){
            answer.push_back(vector<int>());
        }
        answer[depth].push_back(node->val);
        // call first left then right
        dfs(node->left,depth+1);
        dfs(node->right,depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root,0);
        return answer;
    }
};