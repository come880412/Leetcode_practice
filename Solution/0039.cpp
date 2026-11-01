class Solution {
public:
    void dfs(vector<int>& candidates, int target, int start) {
        if (target == 0) ans.push_back(path);
        else {
            for (int i = start; i < candidates.size(); ++i) {
                int candidate = candidates[i];
                if (candidate > target) break;
                path.push_back(candidate);
                dfs(candidates, target-candidate, i);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> path;

};





