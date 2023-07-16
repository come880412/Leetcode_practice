class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        frequent_words = {}
        
        for s_str in s:
            if s_str not in frequent_words.keys():
                frequent_words[s_str] = 0
            frequent_words[s_str] += 1
        
        for t_str in t:
            if t_str not in frequent_words.keys():
                frequent_words[t_str] = 0
            frequent_words[t_str] -= 1
        
        for value in frequent_words.values():
            if value !=0:
                return False
        
        return True