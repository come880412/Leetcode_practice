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
    ListNode* reverseList(ListNode* head) {
        // ListNode *next = nullptr;
        // ListNode *prev = nullptr;

        // while (head != nullptr) {
        //     next = head -> next;
        //     head -> next = prev;
        //     prev = head;
        //     head = next;
        // }
        // return prev;
        
        // Recursive version
        if (head == nullptr || head -> next == nullptr) return head;

        ListNode *nextNode = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        return nextNode;
    }
};