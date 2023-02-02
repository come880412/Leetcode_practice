class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max_value = float("-inf")
        
        tmp_val = 1
        for num in nums:
            tmp_val *= num
            max_value = max(max_value, tmp_val)
            if num == 0:
                tmp_val = 1
            if num > max_value:
                max_value = num
        
        tmp_val = 1
        for num in nums[::-1]:
            tmp_val *= num
            max_value = max(max_value, tmp_val)
            if num == 0:
                tmp_val = 1
            if num > max_value:
                max_value = num
        
        return max_value
