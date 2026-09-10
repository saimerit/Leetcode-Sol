class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        ans = 0
        i = 1
        while True:
            if word * i in sequence:
                ans+=1
                i+=1
            else:
                break
        return ans
        