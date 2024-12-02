class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordIndex = 1;
        int i = 0, n = sentence.size();
        int m = searchWord.size();

        while (i < n) {
            int start = i;
            while (i < n && sentence[i] != ' ') {
                i++;
            }

            if (i - start >= m) {
                bool isPrefix = true;
                for (int j = 0; j < m; j++) {
                    if (sentence[start + j] != searchWord[j]) {
                        isPrefix = false;
                        break;
                    }
                }
                if (isPrefix) return wordIndex;
            }
            wordIndex++;
            i++;
        }

        return -1;
    }
};