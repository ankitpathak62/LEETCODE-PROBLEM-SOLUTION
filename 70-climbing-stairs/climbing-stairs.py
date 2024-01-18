class Solution:
    def climbStairs(self, n: int) -> int:
        ways = 1

        for i in range(1, (n // 2) + 1):
            product = 1

            for j in range(i, 2 * i):
                product *= (n - j) / (j - i + 1)

            ways += product

        return int(ways)

