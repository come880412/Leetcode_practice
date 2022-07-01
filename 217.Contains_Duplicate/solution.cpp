class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> dict;
        for(int i=0;i<nums.size();++i){
            if(dict.find(nums[i]) == dict.end()){
                dict[nums[i]] = i;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
