class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        long long count = 0;
        
        vector<int> word2Count(26, 0);
        for (char c : word2) {
            word2Count[c - 'a']++;
        }
        
        vector<int> windowCount(26, 0);
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            windowCount[word1[right] - 'a']++;
            
            while (left <= right && isValid(windowCount, word2Count)) {
                count += n - right;
                windowCount[word1[left] - 'a']--;
                left++;
            }
        }
        
        return count;
    }
    
private:
    bool isValid(const vector<int>& windowCount, const vector<int>& word2Count) {
        for (int i = 0; i < 26; i++) {
            if (windowCount[i] < word2Count[i]) {
                return false;
            }
        }
        return true;
    }
};