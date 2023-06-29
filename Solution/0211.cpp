// Implement by myself for first time
class WordDictionary {
public:
    unordered_map<char, WordDictionary*> node;
    bool isWord;
    
    WordDictionary() {
        isWord = false;
    }
    
    void addWord(string word) {
        WordDictionary* root = this;
        
        for(int i=0; i<word.length(); ++i) {
            char subWord = word[i];
            if(root->node.find(subWord) == root->node.end()) // Not found
                root -> node[subWord] = new WordDictionary();
            root = root -> node[subWord];
        }
        root -> isWord = true;
    }
    
    bool search(string word) {
        vector<WordDictionary*> tmpNode={this};
        
        for(int i=0; i<word.length(); ++i) {
            char subWord = word[i];
            
            int tmpSize = tmpNode.size();
            vector<int> deleteIdx;
            for(int j=tmpSize-1; j>=0; --j) {
                if (subWord == '.') {
                    for (auto i : tmpNode[j]->node) {
                        tmpNode.push_back(i.second);
                    }
                    deleteIdx.push_back(j);
                }
                else {
                    if(tmpNode[j] -> node.find(subWord) == tmpNode[j] -> node.end()) { // Not found
                        deleteIdx.push_back(j);
                        continue;
                    }
                    else { // Found
                        tmpNode[j] = tmpNode[j] -> node[subWord];
                    }
                }
            }
            
            for(int k=0; k<deleteIdx.size(); ++k)
                tmpNode.erase(tmpNode.begin() + deleteIdx[k]);
        }
        if(tmpNode.size() == 0)
            return false;
        else {
            for(int i=0; i<tmpNode.size(); ++i) {
                if (tmpNode[i] -> isWord)
                    return true;
            }
        }
        return false;
    }
};


// Reference: https://zxi.mytechroad.com/blog/data-structure/leetcode-211-design-add-and-search-words-data-structure/
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

class WordDictionary {
public:
    unordered_map<string, bool> wordDict;
    unordered_map<int, vector<string>> wordLengCnt;
    
    void addWord(string word) {
        wordDict[word] = true;
        wordLengCnt[word.length()].push_back(word);
    }
    
    bool search(string word) {
        if(word.find('.') == string::npos)
            return wordDict.count(word);
        else {
            for (int i=0; i<wordLengCnt[word.length()].size(); ++i) // Iterate the word with same length
                if(isMatch(word, wordLengCnt[word.length()][i])) return true;
        }
        
        return false;
    }
    
    bool isMatch(const string &targetWord, const string &myWord) {
        for(int i=0; i<myWord.length(); ++i) {
            if(targetWord[i] == '.') continue;
            else if(myWord[i] != targetWord[i]) return false;
        }
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */