class Solution {
public:
    vector<int> lexicalOrder(int n) {
        for (int i = 1; i < 10; ++i)
            helper(n, i);
        return result_;
    }

    void helper(const int n, int curr) {
        if (curr > n) return;
        result_.emplace_back(curr);
        for (int i = 0; i < 10; ++i) {
            int tmp = curr * 10 + i;
            if (tmp > n) return;
            helper(n, tmp);
        }
    }
private:
    vector<int> result_;

};