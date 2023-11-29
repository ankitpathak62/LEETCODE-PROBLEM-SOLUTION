class Solution:
    def hammingWeight(self, n: int) -> int:
        return bin(n).count('1')

# Example usage:
# solution = Solution()
# result = solution.hammingWeight(0b110101)
# print(result)