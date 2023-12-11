class Solution(object):
    def findSpecialInteger(self, arr):
        size = len(arr)
        qtr = size // 4
        cnt = 1
        p = arr[0]
        
        for i in range(1, size):
            if p == arr[i]:
                cnt += 1
            else:
                cnt = 1
            
            if cnt > qtr:
                return arr[i]
            
            p = arr[i]

        return p
        