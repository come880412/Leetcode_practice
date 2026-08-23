class Solution:
    def findDisappearedNumbers(self, nums: list[int], lower: int, upper: int) -> list[list[int]]:
        sorted_nums = sorted({x for x in nums if lower <= x <= upper})
        missing = []
        prev = lower - 1

        for num in sorted_nums:
            if num > prev + 1:
                missing.append([prev+1, num-1])
            prev = num
        if prev < upper:
            missing.append([prev+1, upper])

        return missing