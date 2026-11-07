class Solution:
    def minSubarray(self, nums: list[int], p: int) -> int:
        totalSum = sum(nums)
        t_rem = totalSum % p
        if t_rem == 0:
            return 0
        p_sum = 0
        min_len = len(nums)
        rem_dic = {0:-1}
        for i,n in enumerate(nums):
            p_sum = (p_sum + n) % p
            n_rem = (p_sum - t_rem) % p
            if n_rem in rem_dic:
                min_len = min(min_len, i- rem_dic[n_rem])
            rem_dic[p_sum] = i
        if min_len < len(nums):
            return min_len
        else:
            return -1
        