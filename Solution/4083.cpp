class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int deletions = 0;
        int last = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            if (last != num) {
                deletions += cnt - 1;
                cnt = 0;
            } 
            cnt++;
            last = num;
        }
        deletions += cnt - 1;

        return deletions;
    }
};