class Solution {
public:
    class DisjointSet {
        public:
            DisjointSet (const int n) {
                this->parent = vector<int>(n + 1, 0);
                this->rank = vector<int>(n + 1, 0);
                for (int i = 0; i < n + 1; ++i)
                    this->parent[i] = i;
            }

            int Find(const int u) {
                if (this->parent[u] != u)
                    this->parent[u] = Find(this->parent[u]);
                return this->parent[u];
            }

            bool Union(const int u, const int v) {
                int ru = Find(u);
                int rv = Find(v);
                // They are in the same group
                if (ru == rv) return false;

                // Merge by rank
                if (this->parent[ru] < this->parent[rv])
                    this->parent[ru] = this->parent[rv];
                else {
                    this->parent[rv] = this->parent[ru];
                    if (this->rank[ru] == this->rank[rv])
                        this->rank[ru]++;
                }
                return true;
            }
        private:
            vector<int> parent;
            vector<int> rank;
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet DS(edges.size());
        
        for (auto const &edge: edges) {
            int a = edge[0], b = edge[1];
            if (DS.Find(a) != DS.Find(b))
                DS.Union(a, b);
            else return edge;
        }
        return {};
    }
};