/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<Node*> nodeAtEveryDepth;
    void dfs(Node* node, int depth){
        // deal edge cases: nullptr
        if (node == nullptr) return;
        // either add the node to back of vec or do pointer stuff than change vector
        if (depth == nodeAtEveryDepth.size()){
            nodeAtEveryDepth.push_back(node);
        }else{
            nodeAtEveryDepth[depth]->next = node;
            nodeAtEveryDepth[depth] = node;
        }
        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
    Node* connect(Node* root) {
        dfs(root,0);
        return root;    
    }
};