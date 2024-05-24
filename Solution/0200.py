class Solution:
    def DFS_alg(self, i, j):
        if i < 0 or i >= len(self.grid):
            return False
        if j < 0 or j >= len(self.grid[0]):
            return False

        if self.grid[i][j] == "1":
            self.grid[i][j] = "0"
            self.DFS_alg(i + 1, j)
            self.DFS_alg(i , j + 1)
            self.DFS_alg(i - 1, j)
            self.DFS_alg(i, j - 1)
        else:
            return False
        

    def numIslands(self, grid: List[List[str]]) -> int:
        self.grid = grid

        count = 0
        for m in range(len(self.grid)):
            for n in range(len(self.grid[0])):
                if self.grid[m][n] == "1":
                    count += 1
                    self.DFS_alg(m, n)
        return count
