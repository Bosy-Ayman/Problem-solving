class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int index = coins.size();
        vector<vector<int>> dp(index + 1, vector<int>(amount + 1, 0));

        // Base case: from 0->index-1
        for (int i = 0; i <= index; i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= amount; i++) {
            dp[0][i] = 1e9; 
        }

        
        for (int ind = 1; ind <= index; ind++) {
            for (int T = 0; T <= amount; T++) {
                int notpick = dp[ind - 1][T];
                int pick = 1e9;
                if (T >= coins[ind - 1]) {
                    pick = 1 + dp[ind][T - coins[ind - 1]];
                }
                dp[ind][T] = std::min(pick, notpick);
            }
        }

        return dp[index][amount] == 1e9 ? -1 : dp[index][amount];
    }
};
