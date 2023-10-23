class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n > 0 and (n & (n - 1)) == 0:
            zero_count = 0
            while n > 1:
                zero_count += 1
                n >>= 1
            return zero_count % 2 == 0
        return False