class Solution(object):
    def twoSum(self , nums , target):
        dict = {}
        for i in range(len(nums)):
            dict[target - nums[i]] = i
        for j in range(len(nums)):
            if nums[j] in dict and dict[nums[j]] != j:
                return [dict[nums[j]] , j]