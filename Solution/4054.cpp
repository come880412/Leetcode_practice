class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        stack<pair<int, long long>> s;

        
        long long running = 0, out = 0;
        for (int& num : nums) {
            while (!s.empty() && s.top().first > num) {
                running -= s.top().second;
                s.pop();
            }

            int eq;
            if (!s.empty() && s.top().first == num) eq = s.top().second;
            else eq = 0;

            out += (running - eq);

            int topSize = 1;
            if (!s.empty() && s.top().first == num) {
                topSize = s.top().second + 1;
                s.pop();
            }
                
            s.push({num, topSize});
            running++;
        }             
        return out;            
    }
};