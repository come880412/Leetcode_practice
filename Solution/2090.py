class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
            result = [-1] * len(nums)
            prefix_sums = [0]
            for num in nums:
                prefix_sums.append(prefix_sums[-1] + num)

            window_size = 2*k + 1
            for i, num in enumerate(nums):
                left, right = i - k, i + k
                if left >= 0 and right < len(nums):
                    window_sum = prefix_sums[right+1] - prefix_sums[left]
                    result[i] = window_sum // window_size
                
            return result