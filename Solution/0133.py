"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def DFS(self, node):
        if(node in self.visitedHash.keys()):
            return self.visitedHash[node];
        
        clonedNode = Node(node.val)
        self.visitedHash[node] = clonedNode
        for neighbor in node.neighbors:
            clonedNode.neighbors.append(self.DFS(neighbor))
        return self.visitedHash[node]
    
    def cloneGraph(self, node: 'Node') -> 'Node':
        if(node == None): 
            return node
        self.visitedHash = {}
        
        return self.DFS(node)
        