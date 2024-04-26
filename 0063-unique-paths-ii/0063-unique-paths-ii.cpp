class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1)); 
        return func(m-1, n-1, obstacleGrid, dp);
    }

    int func(int m, int n, vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp) {
        // Base cases
        if (m < 0||n < 0) {
            return 0;
        }
        if (obstacleGrid[m][n] == 1) {
            return 0; // If there is an obstacle, return 0
        }
        if (m == 0 && n == 0) return 1;
       

        // Check if the value has already been computed
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        int right = func(m-1,n,obstacleGrid,dp);
        int down = func(m,n-1,obstacleGrid,dp);

        return dp[m][n]=right+down;
    }
};
