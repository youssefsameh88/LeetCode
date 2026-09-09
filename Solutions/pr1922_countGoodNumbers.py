class Solution(object):
    def countGoodNumbers(self, n):
        if n ==1: return 5
        k = 1000000007
        if(n%2):
            n-=1
            return (5*pow(20,int(n/2),k))%k
        else:
            return (pow(4,int(n/2),k) * pow(5,int(n/2),k)) %k
        

print(Solution().countGoodNumbers(3))