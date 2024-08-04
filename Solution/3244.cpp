class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> s;
        for (int i = 0; i < n; ++i) s.insert(i);

        vector<int> result;
        for (auto const &query : queries) {
            int fromCity = query[0], toCity = query[1];

            // After each query, the nodes which lies between ith Query Edge will disappear after ith Query
            // 0-1-2-3-4   ===> Now, Suppose Add edge (1,4)  
            // ===> Then Shortest path will be 0-1-4 (or nodes 2 and 3 disappear)
            auto it_start = s.lower_bound(fromCity + 1);
            auto it_end = s.upper_bound(toCity - 1);
            s.erase(it_start, it_end);
            
            result.push_back(s.size() - 1);
        }
        return result;
    }
};