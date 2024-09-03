class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for (char word : s) {
            int digit = word - 'a' + 1;
            sum += (digit / 10) + (digit % 10);
        }
        string strSum = to_string(sum);
        int result = sum;
        for (int i = 1; i < k; ++i) {
            strSum = to_string(result);
            result = 0;
            for (char word : strSum) {
                result += word - '0';
            }
        }
        return result;
    }
};