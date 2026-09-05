# BFS solution
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n - 1:
            return False
        visited = [False] * n
        adj_list = [[] for _ in range(n)]
        for edge in edges:
            s, e = edge
            adj_list[s].append(e)
            adj_list[e].append(s)

        queue = deque([(0, -1)])
        visited[0] = True
        while queue:
            curr_node, parrent_node = queue.popleft()
            for node in adj_list[curr_node]:
                if not visited[node]:
                    queue.append((node, curr_node))
                    visited[node] = True
                elif node != parrent_node and visited[node]:
                    return False
        for visit in visited:
            if not visit:
                return False 
        return True

# Union-find solution
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n - 1:
            return False
        parents = [i for i in range(n)]
        def find(node):
            if parents[node] != node:
                parents[node] = find(parents[node])
            return parents[node]
        
        for edge in edges:
            s, e = edge
            rs, re = find(s), find(e)
            if rs == re:
                return False
            parents[re] = rs
        
        root = find(0)
        for i in range(1, n):
            if root != find(i):
                return False
        return True

        

        

        