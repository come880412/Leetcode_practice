class Solution:
    def lower_bound(self, nums, target):
        l, r = 0, len(nums) - 1
        while l <= r:
            m = l + (r - l) // 2
            if nums[m] < target:
                l = m + 1
            else:
                r = m - 1
        return l
        
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        right = self.lower_bound(nums, target + 1)
        left = self.lower_bound(nums, target)

        if left == len(nums) or nums[left] != target:
            return [-1, -1]
        else:
            return [left, right-1]