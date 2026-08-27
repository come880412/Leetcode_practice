class Solution:
    def maxProfit(self, prices: List[int], strategy: List[int], k: int) -> int:
        prefix_sum = [0]
        prefix_profit = [0]
        for i in range(len(prices)):
            prefix_sum.append(prefix_sum[-1] + prices[i])
            prefix_profit.append(prefix_profit[-1] + prices[i]*strategy[i])

        max_profit = prefix_profit[-1]
        for i in range(len(prices) - k + 1):
            old_sum = prefix_profit[i+k] - prefix_profit[i]
            new_sum = prefix_sum[i+k] - prefix_sum[i+k//2]
            new_profit = prefix_profit[-1] - old_sum + new_sum
            max_profit = max(new_profit, max_profit)
        return max_profit
