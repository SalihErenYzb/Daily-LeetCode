 #pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1){
            return new TreeNode(val,root,nullptr);
        }
        vector<pair<TreeNode*,int>> stack = {{root,depth}};
        while (!stack.empty()){
            auto [node, depth2] = stack.back();
            stack.pop_back();
            if (node == nullptr){continue;}
            if (depth2 == 2){
                node->left = new TreeNode(val,node->left,nullptr);
                node->right = new TreeNode(val,nullptr,node->right);
                continue;
            }
            depth2--;
            if (node->right) stack.emplace_back(node->right, depth2);
            if (node->left) stack.emplace_back(node->left, depth2);
        }
        return root;
    }
};