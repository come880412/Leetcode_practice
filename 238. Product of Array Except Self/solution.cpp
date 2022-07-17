class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        
        bool double_zeros=false;
        bool single_zero=false;
        int movingMul=1;
        
        for(int i=0 ; i<nums.size() ; ++i){
            if(nums[i] == 0){
                if(single_zero){
                    double_zeros = true;
                    break;
                }
                single_zero = true;
            }
            
            else{
                movingMul *= nums[i];
            }
        }
        
        for(int i=0 ; i<nums.size() ; ++i){
            if(double_zeros)
                answer.push_back(0);
            
            else{
                
                if(single_zero){
                    if(nums[i] == 0)
                        answer.push_back(movingMul);
                    else
                        answer.push_back(0);
                }
                
                else{
                    answer.push_back(movingMul / nums[i]);
                }
                
            }
        }
        
        return answer;
    }
};