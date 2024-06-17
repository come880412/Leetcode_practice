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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy = ListNode(0, head);
        ListNode *prev = &dummy;
        int count = 0;

        while (head != nullptr) {
            count += 1;
            if (count < left) {
                prev = prev -> next;
                head = head -> next;
            } else if (count >= left && count < right) {
                ListNode *next = head -> next;
                head -> next = next -> next;
                next -> next = prev -> next;
                prev -> next = next;
            } else break;
        }
        return dummy.next;
    }
};