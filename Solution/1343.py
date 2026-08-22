class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        output = running_sum = 0

        for i, num in enumerate(arr):
            running_sum += num

            left = i - k
            if left >= 0:
                running_sum -= arr[left]
            
            if i + 1 >= k and running_sum / k >= threshold:
                output += 1
        return output
                