class Solution(object):
    def romanToInt(self, s):
         dict = { "I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
         l1 = ["V" , "X"]
         l2 = ["L" , "C"]
         l3 = ["D", "M"]
         total = 0
         i = 0
         while i < len(s):
             if i != len(s) -1:
                 if s[i] == "I" and s[i+1] in l1:
                    total += dict[s[i+1]] -1
                    i+=2
                 elif s[i] == "X" and s[i+1] in l2:
                    total += dict[s[i+1]] -10
                    i+=2
                 elif s[i] == "C" and s[i+1] in l3:
                    total += dict[s[i+1]] -100
                    i+=2
                 else:
                    total+=dict[s[i]]
                    i+=1
             else:
                    total+= dict[s[i]]
                    i+=1
         return total
print(Solution().romanToInt("MCMXCIV"))
