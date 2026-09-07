class Solution:
    def countRotations(self, s: str, k: int) -> int:
        n = len(s)
        adj = [int(s[i] == s[i-1]) for i in range(n-1, -1, -1)]
        c = sum(adj)

        out = 0
        for cut_edge in adj:
            if c - cut_edge == k:
                out += 1

        return out
        