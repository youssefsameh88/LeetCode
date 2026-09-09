class Solution:
    def countAnagrams(self, s: str) -> int:
        #starter pack
        lim = 10**9 + 7
        fact = []
        inv_fact = []
        l = len(s)
        Max = l + 1
        fact = [1] * Max
        inv_fact = [1] * Max
        for i in range(1, Max):
            fact[i] = fact[i - 1] * i % lim
        inv_fact[-1] = pow(fact[-1], lim - 2, lim)
        for i in range(Max - 2, -1, -1):
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % lim
        ######################################################
        words = s.split()
        ans = 1
        for word in words:
            freq = {}
            for letter in word:
                freq[letter] = freq.get(letter, 0) + 1
            temp = fact[len(word)]
            for num in freq.values():
                temp = (temp * inv_fact[num]) % lim
            ans = (ans * temp) % lim
            
        return ans