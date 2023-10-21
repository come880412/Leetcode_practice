# Time complexity: O(mn)
# Space complexity: O(mn)
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        DP = [[ 1 for x in range(n)] for y in range (m)]
        
        for i in range(1, m, 1):
            for j in range(1, n, 1):
                DP[i][j] = DP[i-1][j] + DP[i][j-1]
        
        return DP[m-1][n-1]