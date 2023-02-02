class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        
        sort(nums.begin(), nums.end()); // O(nlogn)
        int sum, num_idx1, num_idx2, num_idx3, idx2, idx3;
        // O(n^2)
        for(int i=0 ; i<nums.size()-2 ; ++i){
            // Skip duplicate elements
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            num_idx1 = nums[i];
            
            // Initialization
            idx2 = i + 1;
            idx3 = nums.size() - 1;
            
            while(idx2 != idx3){
                num_idx2 = nums[idx2];
                num_idx3 = nums[idx3];
                sum = num_idx1 + num_idx2 + num_idx3;
                
                if(sum == 0){
                    tmp.push_back(num_idx1);
                    tmp.push_back(num_idx2);
                    tmp.push_back(num_idx3);
                    result.push_back(tmp);
                    tmp.clear();
                    idx2 += 1;
                    // Skip duplicate elements
                    while(nums[idx2] == nums[idx2 - 1] && idx2 < idx3)
                        idx2 += 1;
                }
                
                else if(sum > 0)
                    idx3 -= 1;
                else
                    idx2 += 1;
                
            }
            

        }
        
        return result;
    }
};