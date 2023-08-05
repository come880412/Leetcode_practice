class Solution:
    def search(self, nums: List[int], target: int) -> int:
        start, end = 0, len(nums)-1
        
        while(start <= end):
            mid = (start + end) // 2
        
            if target == nums[mid]:
                return mid
            
            if nums[mid] < nums[start]:
                if (nums[mid] < target and target <= nums[end]):
                    start = mid + 1
                else:
                    end = mid - 1
                
            else:
                if (target < nums[mid] and nums[start] <= target):
                    end = mid -1
                else:
                    start = mid + 1
        
        return -1
                