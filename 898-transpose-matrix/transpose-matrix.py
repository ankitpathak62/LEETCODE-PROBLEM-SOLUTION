class Solution(object):
    def transpose(self, matrix):
        row = len(matrix)
        col = len(matrix[0])
        result = [[0] * row for _ in range(col)]
        
        for i in range(col):
            for j in range(row):
                result[i][j] = matrix[j][i]
                
        return result
        