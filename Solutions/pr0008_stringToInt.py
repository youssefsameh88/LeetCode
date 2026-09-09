class Solution(object):
    def myAtoi(self, s):
        if s =="":
             return 0
        s = " " + s
        n = len(s)
        i = 0
        ans = ""
        sign = 1
        while i < n and s[i] == " " :
            i += 1
        while i < n and (s[i].isdigit() or (s[i] in "-+" and not s[i-1].isdigit())) and sign >= 0 :

            if s[i] in "-+":
                sign -= 1
            if sign < 0:
                break
            ans += s[i]
            i += 1
        if not len(ans) or len(ans) ==1 and ans[0] in"+-":
                return 0
        return 2**31 -1 if float(ans) > 2**31 -1 else -2**31 if float(ans) < -2**31 else int(ans) 
               
    
print(Solution().myAtoi(" ")) 
