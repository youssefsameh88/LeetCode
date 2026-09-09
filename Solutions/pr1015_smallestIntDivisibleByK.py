class Solution(object):
    def smallestRepunitDivByK(self, k):
        if k%5 == 0 or k%2 == 0: return -1
        num , mod, Max = 0 , 0 , 23
        while(num < max):
            mod = mod * 10 + 1
            num += 1
            if(mod % k == 0): return num
        return -1
        
        
        