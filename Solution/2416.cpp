class Trie {
public:
    Trie() : count_(0) {};
    
    void insert(const string& str) {
        Trie* curr = this;
        for (const char c : str) {
            if (curr->m_.find(c) == curr->m_.end())
                curr->m_[c] = new Trie();
            curr = curr->m_[c];
            curr->count_++;
        }
    }

    int search(const char c, Trie*& curr) {
        if (curr->m_.find(c) == curr->m_.end()) {
            return 0;
        }
        else {
            curr = curr->m_[c];
            return curr->count_;
        }
    }

private:
    unordered_map<char, Trie*> m_;
    int count_;
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> answer;
        Trie* dict = new Trie();
        for (const string& word : words)
            dict->insert(word);
        
        for (const string& word : words) {
            int prefix = 0;
            Trie* curr = dict;
            for (int i = 0; i < word.size(); ++i) {
                int tmp = dict->search(word[i], curr);
                if (tmp == 0) break;
                prefix += tmp;
            }
            answer.emplace_back(prefix);
        }
        return answer;
    }
};