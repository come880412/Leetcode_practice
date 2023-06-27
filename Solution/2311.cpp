class Solution {
public:
    int longestSubsequence(string s, int k) {
        string recordBinary = "";
        queue<int> recordOneIdx;
        int maxLen = 0;
        int stringToBinary;
        int oneCount=0;
        
        for(int i=0; i<s.length(); ++i) {
            if(s[i] == '1'){
                recordOneIdx.push(i-oneCount);
                oneCount += 1;
            }
            recordBinary += s[i];
            stringToBinary = stoi(recordBinary, 0, 2);
            if(stringToBinary > k) {
                while(stringToBinary > k) {
                    recordBinary.erase(recordOneIdx.front(), 1);
                    recordOneIdx.pop();
                    stringToBinary = stoi(recordBinary, 0, 2);
                }
            }
            if(recordBinary.length() > maxLen) maxLen = recordBinary.length();
        }
        
        return maxLen;
    }
};