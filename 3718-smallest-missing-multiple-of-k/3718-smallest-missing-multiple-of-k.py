class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        i = k
        while i in nums:
            i += k
        return i
        