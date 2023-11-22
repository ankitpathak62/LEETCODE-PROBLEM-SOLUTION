class Solution(object):
    def findDiagonalOrder(self, nums):
        m = len(nums)
        maxSum, size, index = 0, 0, 0
        map = [[] for _ in range(100001)]
        
        for i in range(m):
            size += len(nums[i])
            for j in range(len(nums[i])):
                _sum = i + j
                map[_sum].append(nums[i][j])
                maxSum = max(maxSum, _sum)
        
        res = [0] * size
        for i in range(maxSum + 1):
            cur = map[i]
            for j in range(len(cur) - 1, -1, -1):
                res[index] = cur[j]
                index += 1
        
        return res
        