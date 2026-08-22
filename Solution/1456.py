class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        running_vowels = vowels = 0

        for i, c in enumerate(s):
            if c in "aeiou":
                running_vowels += 1
            
            left = i - k
            if left >= 0 and s[left] in "aeiou":
                running_vowels -= 1
            
            vowels = max(vowels, running_vowels)
            if vowels == k:
                return vowels
        
        return vowels
