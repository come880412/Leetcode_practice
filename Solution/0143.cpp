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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = second;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        second = prev;

        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (head || second) {
            if (head) {
                tail->next = head;
                head = head->next;
                tail = tail->next;
            }
            
            if (second) {
                tail->next = second;
                second = second->next;
                tail = tail->next;
            }
        }
        head = dummy.next;
    }
};