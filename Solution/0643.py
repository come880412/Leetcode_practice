class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        max_avg = float('-inf')
        running_sum = 0

        for i, num in enumerate(nums):
            running_sum += num

            left = i - k
            if left >= 0:
                running_sum -= nums[left]
            
            if i + 1 >= k:
                max_avg = max(max_avg, running_sum / k)
        return max_avg