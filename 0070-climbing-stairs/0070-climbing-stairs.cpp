class Solution {
public:
    int climbStairs(int n) {
        //int left,right;
        
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1] = 1;
        if(n ==0||n==1){
            return 1;
        }
        for(int i = 2; i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        //left = climbStairs(n-1);
        //right = climbStairs(n-2);
        //return left+right;
        return dp[n];
    }
};