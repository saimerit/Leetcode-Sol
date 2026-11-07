class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        outpu = {}      
        for i,n in enumerate(nums):
            diff = target - n
            if diff in outpu:
                return [outpu[diff],i]
            outpu[n] = i
        