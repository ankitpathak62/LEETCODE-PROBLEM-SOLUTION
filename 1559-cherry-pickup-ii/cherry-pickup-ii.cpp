class Solution {
public:
  int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    // Create 3D DP table with initial values of 0
    int dp[n][m][m];
    memset(dp, 0, sizeof(dp));

    // Set the starting point value (top-left and top-right corner)
    int cherries = 0;
    dp[0][0][m - 1] = grid[0][0] + grid[0][m - 1]; // Add cherries from both robots
    // Iterate through each row from second onwards
    for (int i = 1; i < n; ++i) {
      // Iterate through each column for robot 1
      for (int j = 0; j < m; ++j) {
        // Iterate through each column for robot 2
        for (int k = 0; k < m; ++k) {
          // Skip invalid states:
          // - Both robots in the same row (j > i)
          // - Robot 2 left of robot 1 (k < m - i - 1)
          // - Robot 1 further right than robot 2 (j > k)
          if (j > i || k < m - i - 1 || j > k) continue;
          // Base case: no moves possible, use previous state
          dp[i][j][k] = dp[i - 1][j][k];
          // Explore moves for robot 1:
          // - Up-diagonal with robot 2 at same position
          if (j - 1 >= 0) {
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k]);
          }
          // - Up-diagonal with robot 2 one step left/right
          if (j - 1 >= 0 && k - 1 >= 0)
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1]);
          if (j - 1 >= 0 && k + 1 < m)
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k + 1]);
          // Explore moves for robot 2:
          // - Up-diagonal with robot 1 at same position
          if (j + 1 < m) {
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j + 1][k]);
          }
          // - Up-diagonal with robot 1 one step left/right
          if (j + 1 < m && k - 1 >= 0)
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j + 1][k - 1]);
          if (j + 1 < m && k + 1 < m)
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j + 1][k + 1]);
          // Explore horizontal moves for both robots:
          // - Both robots move left
          if (k - 1 >= 0)
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
          // - Both robots move right
          if (k + 1 < m)
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k + 1]);
          // Add cherries only if robots are in different positions
          if (j != k) {
            dp[i][j][k] += grid[i][j] + grid[i][k];
          } else {
            dp[i][j][k] += grid[i][j]; // Only one robot picks if they land in the same cell
          }
          // Update maximum cherries collected so far
          cherries = max(cherries, dp[i][j][k]);
        }
      }
    }

    return cherries;
  }
};