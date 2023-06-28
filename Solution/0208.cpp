class Trie {
public:
    unordered_map<char, Trie*> node;
    bool isWord;
    
    Trie() {
        isWord = false;
    }
    
    void insert(string word) {
        
        Trie* n = this;
        for(int i=0; i<word.length(); ++i) {
            char letter = word[i];
            
            if(n->node.find(letter) == n->node.end()) // Not found
                n -> node[letter] = new Trie();
            n = n->node[letter];
        }
        n -> isWord = true;
    }
    
    bool search(string word) {
        Trie* n = this;
        
        for(int i=0; i<word.length(); ++i) {
            char letter = word[i];
            
            if(n->node.find(letter) == n->node.end()) // Not found
                return false;
            n = n->node[letter];
        }
        
        return n -> isWord;   
    }
    
    bool startsWith(string prefix) {
        Trie* n = this;
        
        for(int i=0; i<prefix.length(); ++i) {
            char letter = prefix[i];
            
            if(n->node.find(letter) == n->node.end()) // Not found
                return false;
            n = n->node[letter];
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