class Solution {
public:
    // Using Floyd-Warshall algorithm
    // int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    //     vector<vector<int>> graph(n, vector<int>(n, 100000));

    //     for (const auto &e : edges) graph[e[0]][e[1]] = graph[e[1]][e[0]] = e[2];

    //     // Floyd-Warshall algorithm (find shortest path for each two points)
    //     for (int k = 0; k < n; ++k) {
    //         for (int i = 0; i < n; ++i) {
    //             for (int j = 0; j < n; ++j) {
    //                 if (graph[i][j] > graph[i][k] + graph[j][k]) graph[i][j] = graph[i][k] + graph[j][k];
    //             }
    //         }
    //     }

    //     int result = 0;
    //     int minNum = INT_MAX;
    //     for (int i = 0; i < n; ++i) {
    //         int num = 0;
    //         for (int j = 0; j < n; ++j) {
    //             if (i == j) continue;
    //             if (graph[i][j] <= distanceThreshold) num++;
    //         }

    //         if (num <= minNum) {
    //             minNum = num;
    //             result = i;
    //         }
    //     }
    //     return result;
    // }

    // Using Dijkstra algorithm
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph(n, vector<int>(n, 100000));

        for (const auto &e : edges) graph[e[0]][e[1]] = graph[e[1]][e[0]] = e[2];

        int result = 0;
        int minNum = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int num = dijkstra(graph, i, distanceThreshold);
            if (num <= minNum) {
                minNum = num;
                result = i;
            }
        }
        return result;
    }

    int dijkstra(vector<vector<int>> &graph, int src, int distanceThreshold) {
        int V = graph.size();
        vector<int> dist(V, INT_MAX);
        vector<bool> visited(V, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;

            for (int v = 0; v < V; ++v) {
                if (graph[u][v] && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    pq.push({dist[v], v});
                }
            }
        }

        int num = 0;
        for (int i = 0; i < V; ++i) {
            if (i == src) continue;
            if (dist[i] <= distanceThreshold) num++;
        }
        return num;
    }
};