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
    ListNode* doubleIt(ListNode* head) {
        int tmp = 0;
        stack<ListNode*> stack;
        ListNode* node = head;
        while (node != nullptr){
            stack.push(node);
            node = node->next;
        } 
        while (!stack.empty()){
            node = stack.top();
            stack.pop();
            node->val = node->val*2 + tmp;
            tmp = node->val >= 10;
            node->val = node->val%10;
        }
        if (tmp)
            head = new ListNode(tmp,head);
        return head;
    }
};