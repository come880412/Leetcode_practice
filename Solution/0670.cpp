class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        const int n = numStr.size();

        vector<int> record(10, -1);
        for (int i = 0; i < n; ++i) record[numStr[i] - '0'] = i;

        for (int i = 0; i < n; ++i) {
            int curNum = numStr[i] - '0';
            for (int j = 9; j > curNum; --j) {
                if (record[j] != -1 && record[j] > i) {
                    swap(numStr[i], numStr[record[j]]);
                    return stoi(numStr);
                }
            }
        }
        return num;
    }
};