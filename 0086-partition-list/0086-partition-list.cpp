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
    ListNode* partition(ListNode* head, int x) {
        ListNode small(0);
        ListNode large(0);

        ListNode* s = &small;
        ListNode* l = &large;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;

            if (curr->val < x) {
                s->next = curr;
                s = s->next;
            } else {
                l->next = curr;
                l = l->next;
            }

            curr = nextNode;
        }

        l->next = nullptr;
        s->next = large.next;

        return small.next;
    }
};