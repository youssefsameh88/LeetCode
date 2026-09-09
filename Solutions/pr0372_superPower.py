class Solution(object):
    def superPow(self, a, b):
        found_a_match = False
        b1 = ''
        n = len(b) 
        for i in range(n):
           b1 += str(b[i])
        b1 = int(b1)
        for j in range(2,1337):
            if a % 1337 == a**j % 1337:
                found_a_match =True
                break
        if found_a_match and b1 % (j-1):
                return (a**(b1 % (j-1))) % 1337
        else:
            return a**b1 % 1337
print(Solution().superPow(2,[321]))