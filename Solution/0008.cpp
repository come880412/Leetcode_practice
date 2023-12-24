// Time Complexity: O(N)

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int idx = 0;
        
        // Filter out the spaces
        while (idx < s.length() && s[idx] == ' ')
            idx++;

        // Get the sign
        if (idx < s.length() && (s[idx] == '+' || s[idx] == '-')) {
            sign = (s[idx] == '-') ? -1 : 1;
            idx++;
        }

        // Go through the digits (INT_MAX:2147483647, INT_MIN:-2147483648)
        int num = 0;
        while (idx < s.length() && isdigit(s[idx])) {
            int digit = s[idx] - '0';
            if (num > (INT_MAX-digit) / 10)
                return sign == 1 ? INT_MAX : INT_MIN;
            num = (num * 10) + digit;
            idx++;
        }
        return num * sign;
    }
};