class RangeFreqQuery:
    def lower_bound(self, nums, target):
        l, r = 0, len(nums) - 1
        while l <= r:
            m = l + (r - l) // 2
            if nums[m] < target:
                l = m + 1
            else:
                r = m - 1
        return l

    def __init__(self, arr: List[int]):
        self.index_dict = defaultdict(list)
        for i, num in enumerate(arr):
            self.index_dict[num].append(i)

    def query(self, left: int, right: int, value: int) -> int:
        if value in self.index_dict:
            index_list = self.index_dict[value]
            start = self.lower_bound(index_list, left)
            end = self.lower_bound(index_list, right + 1) - 1
            return end - start + 1
        else:
            return 0


# Your RangeFreqQuery object will be instantiated and called as such:
# obj = RangeFreqQuery(arr)
# param_1 = obj.query(left,right,value)