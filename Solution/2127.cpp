// Key idea: split the graph into cycle and chain, and combine them.
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        const int n = favorite.size();

        vector<int> indeg(n, 0);
        for (int num : favorite)
            indeg[num]++;

        queue<int> q;
        vector<bool> visited(n, false);
        vector<int> depth(n, 1);
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
                visited[i] = true;
            }
        }

        // Topological sort to find the cycle node
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            int next = favorite[curr];
            indeg[next]--;
            if (indeg[next]==0) {
                q.push(next);
                visited[next] = true;
            }
            depth[next] = depth[curr] + 1;
        }

        int max_circle_employees = 0;
        int max_link_employees = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                // Find cycle
                int j = i;
                int cnt = 0;
                while (!visited[j]) {
                    cnt++;
                    visited[j] = true;
                    j = favorite[j];
                }

                if (cnt == 2) {
                    max_link_employees += depth[i] + depth[favorite[i]];
                }
                else if (cnt > 2) {
                    max_circle_employees = max(max_circle_employees, cnt);
                }
            }
        }
        return max(max_circle_employees, max_link_employees);
    }
};