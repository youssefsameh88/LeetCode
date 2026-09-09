class Solution(object):
    def maxArea(self, height):
       max_Area = 0
       A = 0
       idx1 = 0
       idx2 = len(height)-1
       while idx1 < idx2:
               A = (idx2 - idx1) * min(height[idx1],height[idx2])  
               if A > max_Area:
                   max_Area = A
               if height[idx1] < height[idx2]:
                     idx1 += 1
               else:
                     idx2 -= 1
       return max_Area
print(Solution().maxArea([1,8,6,2,5,4,8,3,7]))