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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode *result = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list2 -> val <= list1 -> val) {
                result -> next = list2;
                list2 = list2 -> next;
            } else {
                result -> next = list1;
                list1 = list1 -> next;
            }
            result = result -> next;
        }
        if (list1 != nullptr) result -> next = list1;
        if (list2 != nullptr) result -> next = list2;

        return dummy.next;
    }
};