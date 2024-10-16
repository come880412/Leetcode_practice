class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if (a != 0) pq.push({a, 'a'});
        if (b != 0) pq.push({b, 'b'});
        if (c != 0) pq.push({c, 'c'});
        
        string ans;
        while (!pq.empty()) {
            auto [num1, word1] = pq.top();
            pq.pop();

            if (!ans.empty() && ans.back() == word1) {
                if (pq.empty()) break;
                auto [num2, word2] = pq.top();
                pq.pop();
                
                ans += word2;

                if (num2 - 1 > 0) pq.push({num2-1, word2});
                pq.push({num1, word1});
            }
            else {
                int count = min(2, num1);
                ans.append(count, word1);
                if (num1 - count > 0) pq.push({num1-count, word1});
            }

        }
        return ans;
    }
};