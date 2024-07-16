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
    string dfs(TreeNode* tmp,int& dest,vector<char>& s){
        if (tmp == nullptr) return "";
        if (tmp->val == dest) return string(s.begin(),s.end());
        s.push_back('R');
        string right = dfs(tmp->right,dest,s);
        s[s.size()-1] = 'L';
        string left = dfs(tmp->left,dest,s);
        s.pop_back();
        if (right != "") return right;
        return left;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<char> empy;
        string ss = dfs(root,startValue,empy);
        string ds = dfs(root,destValue,empy);
        int i = 0;
        while (i < min(ss.size(),ds.size()) && ss.at(i) == ds.at(i))i++;
        ss = string(ss.size()-i,'U');
        cout << ss;
        return ss+ds.substr(i,ds.size()-i);
    }
};