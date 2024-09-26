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
    void dfs(TreeNode* node, vector<int>& singleAns, int targetSum){
        // deal edge case: targetsum <= 0, node == nullptr etc
        if (!node) {
            return;
        }
        targetSum -= node->val;
        singleAns.push_back(node->val);
        if (!node->left && !node->right){
            if (targetSum == 0){
                answer.push_back(singleAns);
                singleAns.pop_back();
                return;
            }
        }
        // call dfs on other nodes
        dfs(node->left,singleAns,targetSum);
        dfs(node->right,singleAns,targetSum);
        // delete last ele of singleAns
        singleAns.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> singleAns;
        dfs(root,singleAns,targetSum);
        return answer;
    }
};