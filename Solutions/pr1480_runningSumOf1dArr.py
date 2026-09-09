class Solution(object):
    def runningSum(self, nums):
        output = []
        sum = 0
        for i in nums:
            sum += i
            output.append(sum)
        return output
print(Solution().runningSum([1,1,1,1,1]))