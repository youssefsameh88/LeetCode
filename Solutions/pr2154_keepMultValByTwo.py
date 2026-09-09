class Solution(object):
    def findFinalValue(self, nums, original): 
        while original  in nums:
                original *= 2
        return original 
             

print(Solution().findFinalValue([5,3,6,1,12] , 3))
