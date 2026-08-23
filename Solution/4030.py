class Solution:
    def word_to_bit(self, x: str):
        return format(ord(x), '08b')
    
    def isPalindromic(self, s: str) -> bool:
        n = len(s)
        for i in range((n+1) // 2):
            if self.word_to_bit(s[i]) != self.word_to_bit(s[n-i-1])[::-1]:
                return False
        return True