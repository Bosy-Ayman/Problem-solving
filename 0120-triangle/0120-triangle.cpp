
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(); //row
        vector<vector<int>>dp(n,vector<int>(n,-1));
       
        return f(n,0,0,triangle,dp);
        
    }
    int f(int n ,int i ,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        //base case
        if(i ==n-1)return triangle[i][j];
        //return counted value
        if(dp[i][j]!=-1)return dp[i][j];
        int row = triangle[i][j]+f(n,i+1,j+1,triangle,dp);
        int diagonal = triangle[i][j]+f(n,i+1,j,triangle,dp);
        return dp[i][j] = min (row,diagonal);
    }
};