// O(n^2) solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for(int i=0; i<nums.size(); ++i)
            dp.push_back(1);
        int out=1;
        for(int i=0; i<nums.size(); ++i){
            for(int j=0; j<i; ++j){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                    if(dp[i] > out)
                        out = dp[i];
                }
            }
        }
        return out;
    }
};

// O(nlog n) solution
class Solution {
public:
    int BinarySearch(vector<int> res, int num){
        int left=0, right=res.size()-1;
        while(left != right){
            int mid = (left + right) / 2;
            if(res[mid] < num)
                left = mid + 1;
            else if(res[mid] > num)
                right = mid;
            else
                return mid;
        }
        return right;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res{nums[0]};
        for(int i=1; i<nums.size(); ++i){
            int num = nums[i];
            cout<<num<<" ";
            if(num > res[res.size()-1])
                res.push_back(num);
            else{
                int idx = BinarySearch(res, num);
                res[idx] = num;
            }
        }
        return res.size(); 
    }
};