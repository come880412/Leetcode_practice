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
    ListNode *findKGroup(ListNode *head, int k) {
        int cnt = 1;
        while (head != nullptr && cnt < k) {
            head = head -> next;
            cnt++;
        }
        if (cnt == k) return head;
        else return nullptr;
    }

    ListNode *reverseNode(ListNode *head, int k) {
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        int cnt = 0;
        
        while (cnt < k) {
            next = head -> next;
            head -> next = prev;
            prev = head;
            head = next;
            cnt += 1;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy = ListNode(0, head);
        ListNode *prevGroupEnd = &dummy;

        while (true) {
            ListNode *kGroupEnd = findKGroup(prevGroupEnd -> next, k);
            if (kGroupEnd == nullptr) break;

            ListNode *groupStart = prevGroupEnd -> next;
            ListNode *nextGroupStart = kGroupEnd -> next;
            prevGroupEnd -> next = reverseNode(groupStart, k);
            groupStart -> next = nextGroupStart;
            prevGroupEnd = groupStart;
        }
        return dummy.next;
    }
};