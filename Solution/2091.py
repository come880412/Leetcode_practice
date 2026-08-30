class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        n = len(nums)
        min_num_idx, max_num_idx = 0, 0
        for i in range(n):
            if nums[i] < nums[min_num_idx]:
                min_num_idx = i
            if nums[i] > nums[max_num_idx]:
                max_num_idx = i
        
        out = max(max_num_idx, min_num_idx) + 1
        out = min(out, n - min(min_num_idx, max_num_idx))
        out = min(out, min_num_idx + 1 + n - max_num_idx)
        out = min(out, max_num_idx + 1 + n - min_num_idx)
        return out