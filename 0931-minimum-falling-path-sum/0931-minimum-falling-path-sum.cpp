class Solution {
public:
   int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size(); 
    int m = matrix[0].size(); 

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++) {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = matrix[i][j] + dp[i - 1][j];
            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0) {
                leftDiagonal += dp[i - 1][j - 1];
            } else {
                leftDiagonal += 1e9; // A very large positive value to represent an invalid path
            }

            // Right diagonal direction (if it's a valid move)
            int rightDiagonal = matrix[i][j];
            if (j + 1 < m) {
                rightDiagonal += dp[i - 1][j + 1];
            } else {
                rightDiagonal += 1e9; // A very large positive value to represent an invalid path
            }
            dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
        }
    }

    // Find the minimum value in the last row of dp, which represents the minimum path sums ending at each cell
    int mini = INT_MAX;
    for (int j = 0; j < m; j++) {
        mini = min(mini, dp[n - 1][j]);
    }

    return mini;
}
 
};