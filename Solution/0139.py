class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        word_set = set(wordDict)
        dp = [0] * (n+1)

        dp[0] = 1
        for i in range(1, n+1):
            for j in range(i):
                if dp[j] and s[j:i] in word_set:
                    dp[i] = 1
                    break
        return dp[-1] == 1
