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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = ListNode(-1, head);
        ListNode *tmpNode = &dummy;

        int count = 1;
        while(head != nullptr) {
            if (count > n) tmpNode = tmpNode -> next;
            
            count += 1;
            head = head -> next;
        }

        tmpNode -> next = tmpNode -> next -> next;
        return dummy.next;
    }
};