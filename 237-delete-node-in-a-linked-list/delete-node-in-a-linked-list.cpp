/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        while (node->next != nullptr){
            node->val = node->next->val;
            if (node->next->next == nullptr){
                node->next = nullptr;
                return;
            }
            node = node->next;
        }
        
    }
};