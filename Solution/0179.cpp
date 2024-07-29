class Solution {
public:
    static bool mySort(int a, int b) {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), mySort);
        string result = "";
        for (const int num : nums) {
            result += to_string(num);
        }
        if (result[0] == '0') return '0';
        else return result;
    }
};