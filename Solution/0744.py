class Solution:
    def lower_bound(self, letters, target):
        l, r = 0, len(letters) - 1
        while l <= r:
            m = l + (r - l) // 2
            if letters[m] <= target:
                l = m + 1
            else:
                r = m - 1
        return l

    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        pos = self.lower_bound(letters, target)
        if pos == len(letters):
            return letters[0]
        else:
            return letters[pos]
    