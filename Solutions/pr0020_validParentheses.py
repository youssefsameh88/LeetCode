class Solution(object):
    def isValid(self, s):
     stack =[]
     map = { ")":"(" , "]":"[" , "}":"{" }     
     for i in range(len(s)):
         stack.append(s[i])
         n = len(stack) 
         if s[i] in ")}]" and stack[n-2] == map[stack[n-1]]:
             stack.pop()
             stack.pop()  
     return True if stack == [] else False 
 
print(Solution().isValid("(){[}]"))
        