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
        ListNode dummyL = ListNode();
        ListNode dummyR = ListNode();
        ListNode *leftNode = &dummyL;
        ListNode *rightNode = &dummyR;

        while (head != nullptr) {
            if (head -> val < x) {
                leftNode -> next = head;
                leftNode = leftNode -> next;
            }
            else {
                rightNode -> next = head;
                rightNode = rightNode -> next;
            }

            head = head -> next;
        }
        rightNode -> next = nullptr;
        leftNode -> next = dummyR.next;

        return dummyL.next;
    }
};