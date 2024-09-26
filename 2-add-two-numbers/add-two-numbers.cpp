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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmpNode = new ListNode();
        ListNode* answer = tmpNode;
        int tmp = 0;
        while (l1 != nullptr || l2 != nullptr || tmp){
            tmpNode->next = new ListNode();
            tmpNode = tmpNode->next;
            if (l1 != nullptr) tmp += l1->val;
            if (l2 != nullptr) tmp += l2->val;
            tmpNode->val = tmp%10;
            tmp = tmp >= 10;
            if (l1) l1= l1->next;
            if (l2) l2 = l2->next;
        }
        return answer->next;
    }
};