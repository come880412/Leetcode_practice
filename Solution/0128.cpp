class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet;
        int out=0;
        
        for (int i=0; i<nums.size(); ++i)
            numsSet.insert(nums[i]);
            
        for (int i=0; i<nums.size(); ++i) {
            int num = nums[i];
            if (!numsSet.count(num)) continue;
            int tmpFront=num, tmpBack=num;
            
            while(numsSet.count(tmpFront + 1)) {
                numsSet.erase(tmpFront + 1);
                tmpFront += 1;
            }
            
            while(numsSet.count(tmpBack - 1)) {
                numsSet.erase(tmpBack - 1);
                tmpBack -= 1;
            }
            
            out = max(out, (tmpFront-tmpBack+1));
                
        }
        
        return out;
    }
};