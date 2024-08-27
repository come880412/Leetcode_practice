class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        // Dijkstra
        vector<double> dist(n, 0.0);
        vector<bool> visited(n, false);
        priority_queue<pair<double, int>> pq;

        pq.push({1.0, start_node});
        dist[start_node] = 1.0;
        while (!pq.empty()) {
            auto [currProb, fromIdx] = pq.top();
            pq.pop();

            if (fromIdx == end_node) return dist[end_node];

            if (visited[fromIdx]) continue;
            visited[fromIdx] = true;
            
            for (int i = 0; i < graph[fromIdx].size(); ++i) {
                auto [toIdx, prob] = graph[fromIdx][i];
                if (prob && !visited[toIdx] && dist[fromIdx] * prob > dist[toIdx]) {
                    dist[toIdx] = dist[fromIdx] * prob;
                    pq.push({dist[toIdx], toIdx});
                }
            }
        }
        return dist[end_node];
    }
};