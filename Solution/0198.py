class Solution:
    def rob(self, nums: List[int]) -> int:
        out = [0, nums[0]]
        
        for i in range(1, len(nums)):
            out.append(max(out[i], nums[i] + out[i-1]))
        
        return out[len(nums)]