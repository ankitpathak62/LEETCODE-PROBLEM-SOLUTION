class Solution:
    def reverse(self, num: int) -> int:
        rev = 0
        while num > 0:
            rev = rev * 10 + num % 10
            num //= 10
        return rev

    def countNicePairs(self, nums: List[int]) -> int:
        mod = 1000000007

        nums = [num - self.reverse(num) for num in nums]
        nums.sort()

        res = 0
        i = 0
        while i < len(nums) - 1:
            cont = 1
            while i < len(nums) - 1 and nums[i] == nums[i + 1]:
                cont += 1
                i += 1
            res = (res % mod + (cont * (cont - 1)) // 2) % mod
            i += 1

        return int(res % mod)
        