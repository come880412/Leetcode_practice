class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        
        vector<int> onesPrefix(n + 1, 0);
        vector<int> zerosPrefix(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            onesPrefix[i] = onesPrefix[i - 1] + (s[i - 1] == '1' ? 1 : 0);
            zerosPrefix[i] = zerosPrefix[i - 1] + (s[i - 1] == '0' ? 1 : 0);
        }
        
        int result = 0;
        for (int start = 0; start < n; ++start) {
            for (int end = start + 1; end <= n; ++end) {
                int onesSum = onesPrefix[end] - onesPrefix[start];
                int zerosSum = zerosPrefix[end] - zerosPrefix[start];

                if (zerosSum * zerosSum > onesSum) end += (zerosSum * zerosSum - onesSum - 1); // Jump to the next possible solution
                if (onesSum >= zerosSum * zerosSum) {
                    result++;
                    int sqrtOne = sqrt(onesSum);
                    
                    // Jump to the position where zero is greater than one.
                    if (sqrtOne > zerosSum) {
                        result += (end + (sqrtOne - zerosSum) >= n) ? n - end : sqrtOne - zerosSum;
                        end += (sqrtOne - zerosSum);
                    }
                }
            }
        }
        return result;
    }
};