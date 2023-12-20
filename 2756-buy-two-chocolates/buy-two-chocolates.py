class Solution(object):
    def buyChoco(self, arr, key):
        ans = float('inf')

        for i in range(len(arr)):
            for j in range(len(arr)):
                if i != j:
                    total = arr[i] + arr[j]
                    ans = min(ans, total)

        fin = key - ans
        if(fin>=0):
            return fin
        else:
            return key
        