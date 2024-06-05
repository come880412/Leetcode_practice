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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy = ListNode(0);

        while (head != nullptr) {
            ListNode *record = &dummy;
            int currVal = head -> val;

            while (record -> next != nullptr) {
                if (currVal > record -> next -> val) {
                    record = record -> next;
                } else {
                    break;
                }
            }
            ListNode *newNode = new ListNode(currVal);
            newNode -> next = record -> next;
            record -> next = newNode;
            head = head -> next;
        }
        return dummy.next;
    }
};