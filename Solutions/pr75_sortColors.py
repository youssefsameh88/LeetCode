class Solution(object):
    def sortColors(self, nums):
        c = [0,0,0]
        for i in nums:
            if i == 0: c[0] += 1
            elif i == 1: c[1] += 1
            else: c[2] += 1

        k = 0
        j = 0
        while j <len(nums):
            if c[k] == 0:
                k += 1
                continue
            nums[j] = k
            c[k] -=1
            if k == 3:
                break
            j +=1

        return nums
print(Solution().sortColors([1,2 , 0 ,2,2,2,1,0,1]))
                       