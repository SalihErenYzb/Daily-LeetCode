class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans = "zzzzzzzzzzz";
        string deneme = "a";
        dfs(root,"",ans);
        return ans;
    }
    void dfs(TreeNode* root, string st,string& ans){
        string l = (char)('a' + root->val) + st;
        if (root->left == nullptr && root->right == nullptr){
            ans = l > ans ? ans : l;
            return;
        }
        if (root->left == nullptr){
            dfs(root->right,l,ans);
            return;
        }
        if (root->right == nullptr){
            dfs(root->left, l,ans);
            return;
        }
        dfs(root->left,l,ans);
        dfs(root->right,l,ans);
    }
};