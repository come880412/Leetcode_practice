class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        prefix_xor = [0]
        for num in arr:
            prefix_xor.append(prefix_xor[-1] ^ num)
        
        out = []
        for query in queries:
            s, e = query
            out.append(prefix_xor[e+1] ^ prefix_xor[s])
        return out