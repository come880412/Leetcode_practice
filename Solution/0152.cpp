class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxValue=INT_MIN;
        int recordNum = 1;
            
        for(int i=0 ; i<nums.size() ; ++i){
            recordNum *= nums[i];
            maxValue = max(maxValue, recordNum);
            if(nums[i] == 0) recordNum=1;
        }
        
        recordNum = 1;
        for(int i=nums.size()-1 ; i>=0 ; --i){
            recordNum *= nums[i];
            maxValue = max(maxValue, recordNum);
            if(nums[i] == 0) recordNum=1;
        }
        
        return maxValue;
    }
};