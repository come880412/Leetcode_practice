class Solution:
    def minOperations(self, nums: list[int], sum: int) -> int:
        dp = [float("inf")] * (sum + 1)
        dp[0] = 0

        for num in nums:
            cond = {}
            
            x, c = num, 0
            while x <= sum:
                cond[x] = c
                x *= 2
                c += 1

            x, c = num, 0
            while x != 0:
                if x <= sum:
                    cond[x] = c
                x = x // 2
                c += 1

            for t in range(sum, 0, -1):
                for v, c in cond.items():
                    if v <= t:
                        dp[t] = min(dp[t], dp[t-v] + c)
        out = dp[-1] if dp[-1] != float("inf") else -1
        return out