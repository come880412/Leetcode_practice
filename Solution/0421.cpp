class Trie {
    public:
        Trie *one;
        Trie *zero;
        int val;
        Trie() : one(nullptr), zero(nullptr), val(0) {}

        void insert(int num) {
            Trie *curr = this;
            for (int i = 31; i >= 0; --i) {
                int bit = (num >> i) & 1;
                if (bit == 1) {
                    if (curr -> one == nullptr) curr -> one = new Trie();
                    curr = curr -> one;
                }
                else {
                    if (curr -> zero == nullptr) curr -> zero = new Trie();
                    curr = curr -> zero;
                }
            }
            curr -> val = num;
        }

        int query(int num) {
            Trie *curr = this;
            for (int i = 31; i >= 0; --i) {
                int bit = (num >> i) & 1;
                // Greedy search
                if (bit == 1 && curr -> zero != nullptr) curr = curr -> zero;
                else if (bit == 0 && curr -> one != nullptr) curr = curr -> one;
                else if (bit == 1 && curr -> one != nullptr) curr = curr -> one;
                else if (bit == 0 && curr -> zero != nullptr) curr = curr -> zero;
                else return -1;                
            }
            return num ^ curr -> val;
        }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie *node = new Trie();

        int result = -1;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            node -> insert(num);
            result = max(result, node -> query(num));
        }
        return result;
    }
};