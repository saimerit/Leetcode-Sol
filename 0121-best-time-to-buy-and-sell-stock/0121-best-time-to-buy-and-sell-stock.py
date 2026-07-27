class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        min_p = prices[0]
        max_p = 0
        for i in range(n):
            if prices[i] < min_p:
                min_p = prices[i]
            elif prices[i] - min_p > max_p:
                max_p = prices[i] - min_p
        return max_p
            
              