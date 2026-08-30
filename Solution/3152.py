class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        prefix_sum = [0]
        for i in range(len(nums)):
            bad = 1
            if i == 0 or (nums[i] % 2 != nums[i-1] % 2) :
                bad = 0
            prefix_sum.append(prefix_sum[-1] + bad)
        
        print(prefix_sum)
        out = []
        for query in queries:
            s, e = query
            range_sum = prefix_sum[e+1] - prefix_sum[s+1]
            if range_sum == 0:
                out.append(True)
            else:
                out.append(False)
        return out