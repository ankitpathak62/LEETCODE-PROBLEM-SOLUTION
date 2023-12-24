class Solution(object):
    def minOperations(self, s):
        c_0 = s[0]
        count1 = self.count(s, c_0)
        count2 = self.count(s, '0' if c_0 == '1' else '1') + 1
        return min(count1, count2)

    def count(self, s, c_pre):
        count = 0
        for i in range(1, len(s)):
            current = s[i]
            if current == c_pre:
                count += 1
                c_pre = '0' if c_pre == '1' else '1'
            else:
                c_pre = current
        return count
        