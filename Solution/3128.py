class Solution:
    def numberOfRightTriangles(self, grid: List[List[int]]) -> int:
        row_cnt = [0 for _ in range(len(grid))]
        col_cnt = [0 for _ in range(len(grid[0]))]

        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    row_cnt[i] += 1
                    col_cnt[j] += 1
            
        out = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    out += (row_cnt[i] - 1) * (col_cnt[j] - 1)
        return out