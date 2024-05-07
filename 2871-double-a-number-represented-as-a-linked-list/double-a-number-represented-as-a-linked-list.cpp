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
        int tmp = dfs(head);
        if (tmp)
            head = new ListNode(tmp,head);
        return head;
    }
    int dfs(ListNode*& node){
        int tmp =  node->val*2;
        if (node->next){
            tmp += dfs(node->next);
        }
        node->val = tmp%10;
        return tmp >= 10;
    }

};