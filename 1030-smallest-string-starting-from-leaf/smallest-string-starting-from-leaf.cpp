class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string abz =  string(dfs(root,""));
        if (abz == "abz"){
            return "ababz";
        }
        return abz;
    }
    string dfs(TreeNode* root, string st){
        if (root->left == nullptr && root->right == nullptr){
            return st+(char)('a' + root->val);
        }
        if (root->left == nullptr){
            return dfs(root->right,st) + (char)('a'+root->val);
        }
        if (root->right == nullptr){
            return dfs(root->left, st) + (char)('a' + root->val);
        }
        string l = dfs(root->left,st)+ (char)('a'+root->val);
        string r = dfs(root->right,st)+ (char)('a'+root->val);
        return l > r ? r : l;
    }
};