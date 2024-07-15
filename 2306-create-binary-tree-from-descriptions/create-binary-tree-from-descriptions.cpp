class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> m;
        TreeNode* ans;
        for (int i = 0; i < descriptions.size(); i++)
            m[descriptions[i][1]] = new TreeNode(descriptions[i][1]);
        for (auto tmp: descriptions){
            if (m.find(tmp[0]) == m.end())
                ans = m[tmp[0]] = new TreeNode(tmp[0]);
            TreeNode*& ori = tmp[2] ? m[tmp[0]]->left : m[tmp[0]]->right;
            ori = m[tmp[1]];
        }
        return ans;
    }
};