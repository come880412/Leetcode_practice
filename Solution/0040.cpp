class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> tmp;
        helper(tmp, candidates, 0, target);
        return this->result;
    }
    void helper(vector<int> &tmp, vector<int> &candidates, int curr, int target) {
        if (target == 0) 
            this->result.push_back(tmp);
        else {
            for (int i = curr; i < candidates.size(); ++i) {
                if (candidates[i] > target) break;
                if (i > curr && candidates[i] == candidates[i - 1]) continue; // remove duplicate
                tmp.push_back(candidates[i]);
                helper(tmp, candidates, i + 1, target - candidates[i]);
                tmp.pop_back();
            }
        }
    }
};