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
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> qu;
        qu.push(root);
        vector<int> arr;
        vector<int> indexes;
        while (!qu.empty()){
            arr.clear();
            indexes.clear();
            int sz = qu.size();
            for (int i = 0; i < sz; i++){
                auto top = qu.front();
                qu.pop();
                indexes.push_back(i);
                arr.push_back(top->val);
                if (top->left) qu.push(top->left);
                if (top->right) qu.push(top->right);
            }
            sort(begin(indexes),end(indexes),[&] (int a, int b){
                return arr[a] < arr[b];
            });
            for (int i = 0; i < sz; i++){
                if (i != indexes[i]){
                    swap(indexes[i],indexes[indexes[i]]);
                    ans++;
                    i--;
                }
            }
        }
        return ans;
    }
};