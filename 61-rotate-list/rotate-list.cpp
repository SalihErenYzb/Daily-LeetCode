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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        int size = 1;
        ListNode* tail = head;
        while (tail->next != nullptr){
            tail = tail->next;
            size++;
        }
        tail->next = head;
        k = size - k%size;
        while (k--){
            head = head->next;
            tail = tail->next;
        }
        tail->next = nullptr;
        return head;
    }
};