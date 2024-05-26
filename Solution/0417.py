class Solution:
    def BFS_alg(self, flow_map, start_idx):
        queue = [start_idx]
        while len(queue):
            start_idx = queue.pop(0)
            for j in range(len(self.dir_x)):
                x_idx, y_idx = start_idx[0] + self.dir_y[j], start_idx[1] + self.dir_x[j]
                if x_idx < 0 or y_idx < 0 or x_idx >= self.m or y_idx >= self.n:
                    continue
                if flow_map[x_idx][y_idx] == True or self.heights[x_idx][y_idx] < self.heights[start_idx[0]][start_idx[1]]:
                    continue
                flow_map[x_idx][y_idx] = True
                queue.append([x_idx, y_idx])

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        self.m, self.n = len(heights), len(heights[0])
        self.heights = heights
        pac = [[False for _ in range(self.n)] for _ in range(self.m)]
        alt = [[False for _ in range(self.n)] for _ in range(self.m)]

        self.dir_x = [0, 0, 1, -1]
        self.dir_y = [1, -1, 0 , 0]

        for i in range(self.m):
            pac[i][0] = True
            alt[i][self.n-1] = True

            pac_start_idx = [i, 0]
            alt_start_idx = [i, self.n - 1]

            self.BFS_alg(pac, pac_start_idx)
            self.BFS_alg(alt, alt_start_idx)

        for i in range(self.n):
            pac[0][i] = True
            alt[self.m-1][i] = True

            pac_start_idx = [0, i]
            alt_start_idx = [self.m - 1, i]
            
            self.BFS_alg(pac, pac_start_idx)
            self.BFS_alg(alt, alt_start_idx)
        
        results = []
        for i in range(self.m):
            for j in range(self.n):
                if pac[i][j] and alt[i][j]:
                    results.append([i, j])
        return results
                