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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* out = new ListNode();
        ListNode* tmp = out;
        vector<int> vi(100000,0);
        for (auto list: lists){
            while (list != nullptr){
                vi[list->val+10000]++;
                list = list->next; 
            }
        }
        for (int i = 0; i < vi.size(); i++){
            int el = vi[i];
            while (el--){
                tmp->next = new ListNode(i-10000);
                tmp = tmp->next;
            }
        }
        return out->next;
    }
};