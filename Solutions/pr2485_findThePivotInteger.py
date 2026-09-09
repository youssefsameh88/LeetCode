class Solution(object):
    def pivotInteger(self, n):
       x = (n*(n+1)/2)**0.5
       return int(x) if x - int(x) == 0 else -1