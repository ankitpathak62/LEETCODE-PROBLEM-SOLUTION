 class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size(), col = matrix[0].size();
        int row_index, col_index, start = 0, end = row*col-1, mid;

        while (start <= end) 
        {
            mid = start + (end - start) / 2;
            row_index = mid / col;
            col_index = mid % col;

            if (matrix[row_index][col_index] == target)
            {
                return 1;
            } else if (matrix[row_index][col_index] < target) 
            {
                start = mid + 1;
            } else 
            {
                end = mid - 1;
            }
        }
        return 0;
    }
};