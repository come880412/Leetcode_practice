class Solution:
    def primes(self, x):
        def is_prime(num):
            i = 2
            while i ** 2 <= num:
                if num % i == 0:
                    return False
                i += 1
            return True
        s = []
        for i in range(2, x+1):
            if is_prime(i):
                s.append(i)
        return s

    def prime_factor(self, num):
        s = []
        for prime in self.plist:
            if prime ** 2 > num:
                break
            if num % prime == 0:
                s.append(prime)
                while num % prime == 0:
                    num //= prime
        if num > 1:                           
            s.append(num)
        return s
                
        
    def longestSubarray(self, nums: list[int], k: int) -> int:
        self.plist = self.primes(isqrt(max(nums)))
        fac = [self.prime_factor(v) for v in nums]
        cnt = defaultdict(int)
        left = distinct = ans = 0
        for right in range(len(nums)):
            for p in fac[right]:
                if cnt[p] == 0:
                    distinct += 1
                cnt[p] += 1

            while distinct > k:
                for p in fac[left]:
                    cnt[p] -= 1
                    if cnt[p] == 0:
                        distinct -= 1
                left += 1

            ans = max(ans, right - left + 1)  

        return ans