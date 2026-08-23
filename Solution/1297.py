class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        cnt  = defaultdict(int)
        freq = defaultdict(int)

        window_substr = ""
        for i, c in enumerate(s):
            window_substr += c
            freq[c] += 1

            left = i - minSize + 1
            if left >= 0:
                if len(freq) <= maxLetters:
                    cnt[window_substr] += 1
                freq[s[left]] -= 1
                if freq[s[left]] == 0:
                    freq.pop(s[left])
                window_substr = window_substr[1:]

        max_cnt = 0
        for v in cnt.values():
            max_cnt = max(max_cnt, v)
        return max_cnt

                