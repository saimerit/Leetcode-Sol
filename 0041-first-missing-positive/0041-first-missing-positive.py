class Solution:
    def firstMissingPositive(self, nums: list[int]) -> int:
        # for i in range(1, len(nums)):
        #     if i not in nums:
        #         return i
        n = len(nums)
        for i in range(n):
            while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                target_idx = nums[i] - 1
                nums[i], nums[target_idx] = nums[target_idx], nums[i]

        for i in range(n):
            if nums[i] != i + 1:
                return i + 1

        return n + 1
        