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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode result;
        ListNode* currNode = &result;
        
        unordered_map<int, int> m;
        for (int num : nums) m[num] = 1;

        while (head != nullptr) {
            int currVal = head->val;
            if (m.find(currVal) == m.end()) {
                currNode->next = head;
                currNode = currNode->next;
            }
            head = head->next;
        }
        currNode->next = nullptr;
        return result.next;
    }
};