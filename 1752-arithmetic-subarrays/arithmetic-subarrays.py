class Solution(object):
    def checkArithmeticSubarrays(self, nums, l, r):
        result = []
        for i in range(len(l)):
            result.append(self.is_arithmetic(nums, l[i], r[i]))
        return result

    def is_arithmetic(self, nums, l, r):
        max_val, min_val = float('-inf'), float('inf')

        for i in range(l, r + 1):
            max_val = max(nums[i], max_val)
            min_val = min(nums[i], min_val)

        length = r - l + 1
        if (max_val - min_val) % (length - 1) != 0:
            return False

        diff = (max_val - min_val) // (length - 1)
        if diff == 0:
            return True

        visited = [False] * length

        for i in range(l, r + 1):
            val = nums[i]
            if (val - min_val) % diff != 0:
                return False
            else:
                pos = (val - min_val) // diff
                if visited[pos]:
                    return False
                visited[pos] = True
        return True
        