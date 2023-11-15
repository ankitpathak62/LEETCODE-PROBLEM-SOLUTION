class Solution(object):
    def maximumElementAfterDecrementingAndRearranging(self, arr):
        l = len(arr)
        counter = [0] * l

        for i in range(l):
            counter[min(arr[i] - 1, l - 1)] += 1

        ans = 1
        for i in range(1, l):
            ans = min(i + 1, ans + counter[i])

        return ans
        