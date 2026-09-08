class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        l, r = 0, n-1

        max_area = 0
        while l < r:
            area = min(height[l], height[r]) * (r-l)
            max_area = max(max_area, area)
            if height[l] <= height[r]:
                l += 1
            else:
                r -= 1
        return max_area