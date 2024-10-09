class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> buffer;

        for (char c : s) {
            if (buffer.empty() || c == '(') buffer.push(c);
            else {
                if (buffer.top() == '(') buffer.pop();
                else {
                    buffer.push(c);
                }
            }
        }
        return buffer.size();
    }
};