class Solution:
    def countSpecialIntegers(self, nums: list[int]) -> int:
        cnt = defaultdict(int)
        prev_num = 0
        for num in nums:
            if prev_num != num:
                cnt[num] += 1
            prev_num = num

        out = 0
        for v in cnt.values():
            if v == 1:
                out += 1

        return out
                