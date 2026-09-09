class Solution(object):
    def maximumWealth(self, accounts):
        max_wealth = 0
        for i in range(len(accounts)):
            total = 0
            for j in range(len(accounts[i])):
                total+= accounts[i][j]
            if total > max_wealth:
                max_wealth = total
        return max_wealth