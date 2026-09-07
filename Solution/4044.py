class Solution:
    def countGoodRotations(self, nums: list[int]) -> int:
        n = len(nums)
        pairs = [(nums[i], nums[(i+n//2) % n]) for i in range(n)]
        first_half_sum, last_half_sum = sum(nums[:n//2]), sum(nums[n//2:])

        out = 0
        for pair in pairs:
            first_half_sum = first_half_sum - pair[0] + pair[1]
            last_half_sum = last_half_sum + pair[0] - pair[1]
            if first_half_sum > last_half_sum:
                out += 1
        return out
        