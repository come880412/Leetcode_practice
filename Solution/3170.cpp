class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> tmp;

        std::vector<bool> banned(s.length(), true);

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '*') {
                banned[i] = false;
                int index = -tmp.top().second;
                banned[index] = false;
                tmp.pop();
            } else {
                tmp.push({s[i], -i});
            }
        }

        string result = "";
        for (int i = 0; i < banned.size(); ++i) {
            if (banned[i]) result += s[i];
        }
        return result;
    }
};