class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        sorted_arr = sorted(nums) # Sorted array O(nlogn)
        
        output_arr = []
        # O(n^2) worst case in while loop: 1+2+...+ (n-2)
        for idx1 in range(len(sorted_arr) - 2): 
            p1 = sorted_arr[idx1]
            if idx1 > 0 and p1 == sorted_arr[idx1-1]: # Dulicate cases
                continue
            
            idx2, idx3 = idx1+1, len(sorted_arr)-1
            while idx2 != idx3:
                p2, p3 = sorted_arr[idx2], sorted_arr[idx3]
                
                if p1+p2+p3 == 0:
                    if sorted_arr[idx2-1] == p2 and idx2-1 != idx1: # Dulicate cases
                        idx2 += 1
                    else:
                        output_arr.append([p1, p2, p3])
                        idx2 += 1
                elif p1+p2+p3 < 0:
                    idx2 += 1
                else:
                    idx3 -= 1

        return output_arr
    
    
