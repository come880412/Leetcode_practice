class Solution:
    def maxSum(self, nums: List[int], m: int, k: int) -> int:
        window_sum = max_sum = 0
        cnt = defaultdict(int)

        for i, num in enumerate(nums):
            window_sum += num
            cnt[num] += 1

            left = i - k
            if left >= 0:
                window_sum -= nums[left]
                cnt[nums[left]] -= 1
                if cnt[nums[left]] == 0:
                    cnt.pop(nums[left])

            if i + 1 >= k and len(cnt) >= m:
                max_sum = max(max_sum, window_sum)
        return max_sum



