class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        deque<char> ans(10,'z');
        deque<char> tmp;
        dfs(root,tmp,ans);
        return string(ans.begin(),ans.end());
    }
    void dfs(TreeNode* root, deque<char>& st,deque<char>& ans){
        st.emplace_front(char('a' + root->val));
        if (root->left == nullptr && root->right == nullptr){
            bool b = lexicographical_compare(st.begin(),st.end(),ans.begin(),ans.end()); 
            if (b)
                ans = st;
            st.pop_front();
            return;
        }
        if (root->left != nullptr)
            dfs(root->left,st,ans);
        if (root->right != nullptr)
            dfs(root->right, st,ans);
        st.pop_front();
    }
};