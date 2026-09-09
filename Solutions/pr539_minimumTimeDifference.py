class Solution(object):
    def findMinDifference(self, timePoints):
        timePoints.sort()
        min_diff = 1440
        for i in range(len(timePoints)-1):
            hours = (int(timePoints[i+1][0:2])-int(timePoints[i][0:2])) *60
            minutes = int(timePoints[i+1][3:5])-int(timePoints[i][3:5])
            min_diff = min(hours + minutes , min_diff)

        hours = (int(timePoints[-1][0:2])-int(timePoints[0][0:2])) *60
        minutes = int(timePoints[-1][3:5])-int(timePoints[0][3:5])
        last_chance = min(hours + minutes , 1440 - (hours + minutes) )
        min_diff = min(min_diff ,last_chance )
        return  min(min_diff , 1440 - min_diff)
    
print(Solution().findMinDifference(["02:39","10:26","21:43"]))