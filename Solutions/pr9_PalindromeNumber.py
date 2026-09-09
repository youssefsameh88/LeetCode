class Solution(object):
    def isPalindrome(self, x):
        x = str(x)
        for i in range(len(x)):
            if x[i] != x[len(x) - i-1]:
                return False
        return True
    

    

print(Solution().isPalindrome("011nin110"))