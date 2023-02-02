class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> dict;
        
        vector<int> out;
        int value;
        for(int i=0;i<nums.size();++i){
            value = nums[i];
            if(dict.find(value) == dict.end()){ // not find
                dict[target - value] = i;
            }
            else{ // find
                out.push_back(dict[value]);
                out.push_back(i);
                return out;
            }
        }
        return out;
    }
};
