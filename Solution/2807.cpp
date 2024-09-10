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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* dummy = head;
        while(dummy->next != nullptr) {
            int gcd = std::gcd(dummy->val, dummy->next->val);
            ListNode* newNode = new ListNode(gcd);
            newNode->next = dummy->next;
            dummy->next = newNode;
            dummy = dummy->next->next;
        }
        return head;
    }
};