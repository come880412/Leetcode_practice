class Solution {
public:
    // // BFS algorithm to find the shortest path with weight 1
    int BFS(const vector<vector<int>> &adj, int n) {
        vector<int>distance(n, INT_MAX);
        queue<int> q;
        distance[0] = 0;
        q.push(0);
    
        while (!q.empty()) {
            int curr = q.front();
            if (curr == n - 1) return distance[n - 1];
            q.pop();
            
            for (auto const next : adj[curr]) {
                if (distance[curr] + 1 < distance[next]) {
                    q.push(next);
                    distance[next] = distance[curr] + 1;
                }
            }
        }
        return distance[n - 1];
    }

    // Dijkstra algorithm to find the shortest path with weight 1
    int dijkstra(const vector<vector<int>> &adj, int n) {
        vector<int>distance(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        distance[0] = 0;
        pq.push({0, 0});
    
        while (!pq.empty()) {
            auto [dist, curr] = pq.top();
            pq.pop();
            if (curr == n - 1) return distance[n - 1];
            if (dist > distance[curr]) continue;

            for (auto const next : adj[curr]) {
                if (distance[next] > distance[curr] + 1) {
                    distance[next] = distance[curr] + 1;
                    pq.push({distance[next], next});
                }
            }
        }
        return distance[n - 1];
    }
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) adj[i].push_back(i + 1);
        
        vector<int> result;
        for (auto const query : queries) {
            int fromCity = query[0], toCity = query[1];
            adj[fromCity].push_back(toCity);
            result.push_back(dijkstra(adj, n));
        }
        return result;
    }
};