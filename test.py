class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minValue = 101
        maxProfit = 0
        for i in range(0, len(prices)):
            sellVal = prices[i] - minValue
            if (sellVal > maxProfit):
                maxProfit = sellVal
            if (prices[i] < minValue):
                minValue = prices[i]
        return maxProfit