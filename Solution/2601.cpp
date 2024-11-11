class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        const int n = nums.size();

        int prevNum = 0;
        for (int i = 0; i < n; ++i) {
            int gap = nums[i] - prevNum - 1;
            for (int j = gap; j >= 2; --j) {
                if (isPrime(j)) {
                    nums[i] -= j;
                    break;
                }
            }
            
            cout << nums[i] << " ";
            if (nums[i] <= prevNum) return false;
            prevNum = nums[i];
        }
        return true;
    }

    bool isPrime(int num) {
        int idx = 2;
        while (idx * idx <= num) {
            if (num % idx == 0) return false;
            idx++;
        }
        return true;
    }
};