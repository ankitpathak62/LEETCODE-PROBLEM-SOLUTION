class Solution(object):
    def numberOfMatches(self, n):
        count = 0
        while n > 1:
            rev = n // 2
            count += rev
            n = n - rev
        return count
        