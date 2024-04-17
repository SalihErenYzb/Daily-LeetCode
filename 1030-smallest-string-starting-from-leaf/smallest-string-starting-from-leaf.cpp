class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans = "zzzzzzzzzzz";
        string tmp = "";
        dfs(root,tmp,ans);
        return ans;
    }
    void dfs(TreeNode* root, string& st,string& ans){
        st = char('a' + root->val) + st;
        if (root->left == nullptr && root->right == nullptr){
            ans = min(ans,st);
            st.erase(0,1);
            return;
        }
        if (root->left != nullptr)
            dfs(root->left,st,ans);
        if (root->right != nullptr)
            dfs(root->right, st,ans);
        st.erase(0,1);
    }
};