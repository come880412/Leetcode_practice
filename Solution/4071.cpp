class Solution {
public:
    int compute_dial(int a, int b) {
        return min(abs(a-b), 10 - abs(a-b));
    }
        
    int minRotations(int n, string s) {
        int prev_digit = 0;
        int total = 0;
        for (int i = 0; i < n; ++i) {
            int curr_digit = s[i] - '0';
            total += compute_dial(curr_digit, prev_digit);
            prev_digit = curr_digit;
        }

        prev_digit = 0;
        int result = total;
        int new_digit = s[n-1] - '0';
        for (int k = 0; k < n; ++k) {
            int ori_digit = s[k] - '0';
            int ori_dial = compute_dial(ori_digit, prev_digit);
            int new_dial = compute_dial(new_digit, prev_digit);
            result = min(result, total - ori_dial + new_dial);
            prev_digit = ori_digit;
        }
        return result;
    }
};