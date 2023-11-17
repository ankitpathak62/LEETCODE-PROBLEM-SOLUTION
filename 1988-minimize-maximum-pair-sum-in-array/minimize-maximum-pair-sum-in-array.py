class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        return max( nums[i] + nums[n - i - 1] for i in range(n // 2) )
        