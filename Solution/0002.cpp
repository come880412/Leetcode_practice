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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(-1);
        ListNode* cur = result;
        int sum = 0, carry=0;
        while (l1 != nullptr || l2 != nullptr) {
            int l1_num = l1 != nullptr ? l1->val : 0;
            int l2_num = l2 != nullptr ? l2->val : 0;
            sum = (l1_num + l2_num + carry) % 10;
            carry = (l1_num + l2_num + carry) / 10;
            cur -> next = new ListNode(sum);
            cur = cur -> next;
            if (l1 != nullptr)
                l1 = l1 -> next;
            if (l2 != nullptr)
                l2 = l2 -> next;
            
        }
        if (carry)
            cur -> next = new ListNode(carry);
        
        return result->next;
    }
};