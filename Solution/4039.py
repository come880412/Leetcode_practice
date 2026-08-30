class Solution:  
    def decode(self, num):
        w = num % 10
        d = str(num // 10)
        x = int(d[:w])
        y = int(d[w:])
        return x, y
    
    def sumDecoded(self, nums: list[int]) -> int:
        MOD = 10 ** 9 + 7
        out = 0
        for num in nums:
            x, y = self.decode(num)
            out += (pow(x, y, MOD)) % MOD
        return out
        