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

    def searchInsert(self, nums: List[int], target: int) -> int:
        pos = self.lower_bound(nums, target)
        return pos