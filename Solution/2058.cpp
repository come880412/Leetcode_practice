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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prev = head->val;
        head = head->next;
        vector<int> critical_idx;
        int i = 1;
        while (head->next) {
            int curr = head->val;
            int next = head->next->val;
            if ((curr < next && curr < prev) || (curr > next && curr > prev)) {
                critical_idx.push_back(i);
            }
            ++i;
            prev = curr;
            head = head->next;
        }
        int num_critical = critical_idx.size();
        if (num_critical < 2) return {-1, -1};
        else {
            int maxDist = critical_idx[num_critical-1] - critical_idx[0];
            int minDist = INT_MAX;
            for (int i = 1; i < num_critical; ++i) {
                minDist = min(minDist, critical_idx[i]-critical_idx[i-1]);
            }
            return {minDist, maxDist};
        }
    }
};