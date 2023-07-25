class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        frequent = {}
        
        # O(n)
        for num in nums:
            if num not in frequent.keys():
                frequent[num] = 0
            frequent[num] += 1
    
        frequent_heap = []
        # O(n log k)
        for key, value in frequent.items():
            heappush(frequent_heap, (value, key))
        
        out = []
        # O(k log k)
        for result in heapq.nlargest(k, frequent_heap):
            out.append(result[1])
    
        return out
        