/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {        
        if (!head) return nullptr;
        if (head->next == nullptr) return new TreeNode(head->val);
        if (head->next->next == nullptr){
            return new TreeNode(head->val,nullptr,new TreeNode(head->next->val));
        }
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while (fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // make the next of slow a node and recursively call for left and right
        TreeNode* answer = new TreeNode(slow->next->val);
        answer->right = sortedListToBST(slow->next->next);
        slow->next = nullptr;
        answer->left = sortedListToBST(head);
        return answer;
    }
};