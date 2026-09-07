class Solution:
    def countGroups(self, position: list[int], speed: list[int], distance: int) -> int:
        n = len(position)
        ans = 1
        curr_min = speed[-1]

        for i in range(n-2, -1, -1):
            if position[i+1] - position[i] > distance and speed[i] <= curr_min:
                ans += 1
                curr_min = speed[i]
            
        return ans