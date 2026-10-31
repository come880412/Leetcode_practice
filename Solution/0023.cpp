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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) pq.push({lists[i]->val, i});
        }

        ListNode dummy;
        ListNode* tail = &dummy;
        while (!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();
            tail->next = new ListNode(val);
            tail = tail->next;
            lists[idx] = lists[idx]->next;
            if (lists[idx]) pq.push({lists[idx]->val, idx});
        }
        return dummy.next;

    }
};