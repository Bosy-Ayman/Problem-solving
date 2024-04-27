class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int index = coins.size();
        vector<vector<int>>dp(index,vector<int>(amount+1,0));
        //BASE Condition
       for (int i = 0; i <= amount; i++) {
        if (i % coins[0] == 0)
            dp[0][i] = 1;
       
    }
        int pick,notpick;
        for(int ind = 1 ;ind<index;ind++){
            for(int target = 0 ;target<= amount;target++){
                  
                int notpick = dp[ind-1][target]; 
                int pick = 0;
                if (coins[ind] <= target) {
                    pick = dp[ind] [target-coins[ind]]; 
                }
                dp[ind][target]=pick + notpick;
            }
        }
   
        return dp[index-1][amount];
    }

};