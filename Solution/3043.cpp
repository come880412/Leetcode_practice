class Trie {
public:
    Trie() {};

    void insert(const string& str) {
        Trie* curr = this;
        for (char s : str) {
            int num = s - '0';
            if ((curr->m_).find(num) == (curr->m_).end()) 
                curr->m_[num] = new Trie();
            curr = curr->m_[num];
        }
    }

    int search(const string& str) {
        int LCP = 0;
        Trie* curr = this;
        for (char s : str) {
            int num = s - '0';
            if ((curr->m_).find(num) == (curr->m_).end())  return LCP;
            else {
                LCP++;
                curr = curr->m_[num];
            }
        }
        return LCP;
    }
private:
    unordered_map<int, Trie*> m_;
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int LCP = 0;
        Trie* dict = new Trie();
        for (int num : arr1) dict->insert(to_string(num));

        for (int num : arr2) {
            int tmp = dict->search(to_string(num));
            LCP = max(LCP, tmp);
        }
        return LCP;
    }


};