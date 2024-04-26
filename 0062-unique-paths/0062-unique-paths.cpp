class Solution {
public:
    int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n,-1));
       return func(m-1,n-1,dp);
    }
    
    int func(int m, int n, vector<vector<int>>& dp){
         //base case : mat7arkna4 aslan
        if(m == 0 &&n == 0){
            return 1;
        }
        
        if (m< 0||n<0){
            return 0;
        }
       //memoization: if the value has been previously computed
        if(dp[m][n]!= -1)return dp[m][n]; 
            
        int right = func(m-1,n,dp);
        int down = func(m,n-1,dp);
        return dp[m][n] = right+down;
    }
};