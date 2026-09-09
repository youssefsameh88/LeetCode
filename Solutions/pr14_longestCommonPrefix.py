class Solution(object):
    def longestCommonPrefix(self, strs):
            longest_prefix = ""
            stop = False 
            min = len(strs[0])
            for i in range(len(strs)):
                if len(strs[i]) <= min:
                    min = len(strs[i])
            for i in range(min):
                for j in range(len(strs)):
                 if strs[j-1][i] != strs[j][i]:
                    stop = True
                    break
                if  stop:
                    break
                longest_prefix += strs[j][i]
            return longest_prefix
            
print(Solution().longestCommonPrefix(["flying ", "fly"]))