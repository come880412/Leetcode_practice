class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        priority_queue<pair<int,int>> pq; 
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) pq.push({i, freq[i]});
        }

        string ans;
        while (!pq.empty()) {
            auto [charIdx, cnt] = pq.top();
            pq.pop();

            int use = min(cnt, repeatLimit); 
            ans += string(use, 'a' + charIdx);
            cnt -= use;

            if (cnt > 0) {
                if (!pq.empty()) {
                    auto [charIdx2, cnt2] = pq.top();
                    pq.pop();

                    ans += ('a' + charIdx2);
                    cnt2 -= 1;

                    if (cnt2 > 0) pq.push({charIdx2, cnt2});
                    pq.push({charIdx, cnt});
                } else break;
            }
        }
        return ans;
        
        return ans;
    }
};