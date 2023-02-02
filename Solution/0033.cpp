class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        
        int m;
        
        while(s <= e){
            m = floor((s + e) / 2);
            
            if(nums[m] == target)
                return m;
            
            if(nums[m] < nums[s]){
                if(target > nums[m] && nums[e] >= target) s = m + 1;
                else e = m - 1;
            }
            
            else{
                if(target < nums[m] && nums[s] <= target) e = m - 1;
                else s = m + 1;
            }
            
            
        }
        
        return -1;
        
    }
};