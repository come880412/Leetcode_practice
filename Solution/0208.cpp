class Trie {
public:
    unordered_map<char, Trie*> map;
    bool isLeaf;
    Trie() {
        this->isLeaf = false;
    }
    
    void insert(string word) {
        int n = word.size();

        Trie *curr = this;
        for (int i = 0; i < n; ++i) {
            if (curr->map.find(word[i]) == curr->map.end()) {
                Trie *newNode = new Trie();
                curr->map[word[i]] = newNode;
            }
            curr = curr->map[word[i]];
        }
        curr->isLeaf = true;
    }
    
    bool search(string word) {
        int n = word.size();

        Trie *curr = this;
        for (int i = 0; i < n; ++i) {
            if (curr->map.find(word[i]) == curr->map.end()) return false;
            curr = curr->map[word[i]];
        }

        if (curr->isLeaf) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();

        Trie *curr = this;
        for (int i = 0; i < n; ++i) {
            if (curr->map.find(prefix[i]) == curr->map.end()) return false;
            curr = curr->map[prefix[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */