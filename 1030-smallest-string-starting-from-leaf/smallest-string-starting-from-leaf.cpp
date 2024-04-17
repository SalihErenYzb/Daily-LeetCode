class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans = "zzzzzzzzzzz";
        string tmp = "";
        dfs(root,tmp,ans);
        return ans;
    }
    void dfs(TreeNode* root, string& st,string& ans){
        st.push_back(char('a' + root->val));
        if (root->left == nullptr && root->right == nullptr){
            reverse(st.begin(),st.end());
            ans = st > ans ? ans : st;
            reverse(st.begin(),st.end());
            st.pop_back();
            return;
        }
        if (root->left != nullptr)
            dfs(root->left,st,ans);
        if (root->right != nullptr)
            dfs(root->right, st,ans);
        st.pop_back();
    }
};