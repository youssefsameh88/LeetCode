class Solution(object):
    def myPow(self, x, n):
        n1 = abs(n)
        bin_weights = []
        bin_values = []
        mult = 1
        count = 0
        while n1 != 0:
            bin_values.append(n1 % 2)
            n1 = int(n1 / 2)
            bin_weights.append(count)
            mult *= 2
            count+=1
            
        ans = 1
        for i in range(len(bin_values)):
            if bin_values[i]:
                y = x
                for j in range(bin_weights[i] ):
                    y *= y
            else:
                y = 1
            ans *= y
        return ans if n > 0 else 1/ans
                
print(Solution().myPow(2 , 2000 ))