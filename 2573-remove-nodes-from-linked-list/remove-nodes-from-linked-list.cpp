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
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        int max1 = -1;
        recursiveMax(head,max1);
        return head;
    }
    void recursiveMax(ListNode*& node, int& max1){
        if (node->next != nullptr)
            recursiveMax(node->next,max1);
        if (node->val < max1){
            ListNode* tmp = node;
            node = node->next;
            delete tmp;
        }
        max1 = max(max1,node->val);
    }
};