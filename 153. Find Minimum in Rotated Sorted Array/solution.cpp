class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0, e=nums.size()-1;
        
        // only one element or non-rotated array
        if(nums[e] >= nums[s])
            return nums[s];
        
        int m;
        int minVal=INT_MAX;
        while(s <= e){
            m = floor((s+e) / 2);
            
            if(nums[m] >= nums[s] && nums[m] > nums[e])
                s = m + 1;
            else
                e = m - 1;
            
            if(nums[m] <= minVal)
                minVal = nums[m];

        }
        
        return minVal;
    }
};