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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m, vector<int>(n, -1));

        int xBoundary = m - 1, yBoundary = n;
        int inc = 0;
        int dirIdx = 0;
        pair<int, int> currPos = {0, 0};
        while (head != nullptr) {
            auto [xCurr, yCurr] = currPos;

            result[xCurr][yCurr] = head->val;
            head = head->next;
            ++inc;
            if ((dirIdx % 2 == 1 && inc >= xBoundary) || (dirIdx % 2 == 0 && inc >= yBoundary)) {
                xBoundary -= abs(dirs[dirIdx].first);
                yBoundary -= abs(dirs[dirIdx].second);
                inc = 0;
                dirIdx = (dirIdx + 1) >= dirs.size() ? 0 : dirIdx + 1;
            }

            auto [xDir, yDir] = dirs[dirIdx];
            currPos.first += xDir;
            currPos.second += yDir;
        }
        return result;
    }
private:
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

};