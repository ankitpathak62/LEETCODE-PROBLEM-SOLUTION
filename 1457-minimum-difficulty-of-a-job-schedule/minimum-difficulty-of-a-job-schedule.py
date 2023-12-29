class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if d > n : return -1
        if d == n : return sum(jobDifficulty)

        @cache
        def recur(i : int, days : int) :
            if i == n or days == 1 : return max(jobDifficulty[i : ])

            res = 9e9
            for j in range(i, n - days + 1) :
                jobMax = max(jobDifficulty[i : j + 1]) + recur(j + 1, days - 1)
                res = min(res, jobMax)
            
            return res
        
        return recur(0, d)