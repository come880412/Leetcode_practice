class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
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

        