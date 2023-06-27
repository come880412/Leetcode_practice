class Solution:
    def climbStairs(self, n: int) -> int:
        output = [1, 1]
        
        for i in range(1, n):
            output.append(output[i] + output[i-1])
        
        return output[n]
            
        