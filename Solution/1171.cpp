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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> recordMap;
        ListNode dummy = ListNode(0, head);
        ListNode *result = &dummy;
        
        recordMap[0] = result;
        result = result -> next;
        int sum = 0;
        while (result != nullptr) {
            sum += result -> val;
            if (recordMap.find(sum) == recordMap.end()) recordMap[sum] = result;
            else {
                ListNode *tmpNode = recordMap[sum] -> next;
                int tmpSum = sum;
                while (tmpNode != result) {
                    tmpSum += tmpNode -> val;
                    recordMap.erase(tmpSum);
                    tmpNode = tmpNode -> next;
                }
                recordMap[sum] -> next = result -> next;
            }
            result = result -> next;
        }
        return dummy.next;
    }
};