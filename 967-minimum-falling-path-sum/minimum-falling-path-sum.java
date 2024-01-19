class Solution {
    private int solveMemo(int[][] matrix, int row, int col, int[][] dp){
        // Base Case
        if(row>=matrix.length || col>=matrix[0].length || col<0){
            return Integer.MAX_VALUE;
        }
        if(row == matrix.length-1){
            if(col<matrix[0].length && col>=0) return matrix[row][col];
            else return 0;
        }

        // Step-2 =>if result(.ie. dp[row][col]) is already calculated just return it.
        if(dp[row][col] != Integer.MIN_VALUE){
            return dp[row][col];
        }


        // step-3 =>if not yet calculaed just calculate and store it in the memoization matrix (.ie. dp[row][col])
        return dp[row][col] = matrix[row][col] + Math.min(solveMemo(matrix, row+1, col, dp), Math.min(solveMemo(matrix, row+1, col-1, dp), solveMemo(matrix, row+1, col+1, dp)));
    }



    public int minFallingPathSum(int[][] matrix) {
        //step-1 => memoization matrix(.ie.dp[][]) creation
        int[][] dp = new int[matrix.length][matrix[0].length];
        for(int[] i:dp){
            Arrays.fill(i, Integer.MIN_VALUE);
        }

        int res = Integer.MAX_VALUE;
        for(int i=0; i<matrix.length; i++){
            res = Math.min(res, solveMemo(matrix, 0, i, dp));
        }
        return res;
    }
}