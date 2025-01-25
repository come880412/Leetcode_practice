class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        const int n = nums.size();
        
        vector<pair<int, int>> pos(n);
        for (int i = 0; i < nums.size(); ++i) 
            pos[i] = make_pair(nums[i], i);
        
        sort(pos.begin(), pos.end(), greater<pair<int, int>>());
        vector<vector<int>> connected;
        vector<int> tmp;
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && pos[i-1].first - pos[i].first > limit) {
                idx++;
                connected.emplace_back(tmp);
                tmp.clear();
            }
            tmp.emplace_back(pos[i].first);
            nums[pos[i].second] = idx;
        }
        if (!tmp.empty()) connected.emplace_back(tmp);

        for (int i = 0; i < n; ++i) {
            int num = connected[nums[i]].back();
            connected[nums[i]].pop_back();
            nums[i] = num;
        }
        return nums;
    }
};