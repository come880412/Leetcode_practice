class Solution {
public:
    int digitSum(int num) {
        int ans = 0;
        while (num != 0) {
            ans += num % 10;
            num /= 10;
        }
        return ans;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> digit_sum;
        unordered_map<int, int> pos;

        for (int i = 0; i < n; ++i) {
            digit_sum.push_back({digitSum(nums[i]), nums[i]});
            pos[nums[i]] = i;
        }

        sort(digit_sum.begin(), digit_sum.end());

        int swap_num = 0;
        for (int i = 0; i < n; ++i) {
            int target_num = digit_sum[i].second;

            if (target_num == nums[i]) continue;
            int ori_pos = pos[target_num];

            swap(nums[i], nums[ori_pos]);
            pos[nums[i]] = i;
            pos[nums[ori_pos]] = ori_pos;

            swap_num++;
        }
        return swap_num;
    }
};