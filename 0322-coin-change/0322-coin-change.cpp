class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int index = coins.size();
        vector<vector<int>> dp(index, vector<int>(amount + 1, -1));
        int result = f(index - 1, amount, coins, dp);
        return result == 1e9 ? -1 : result; // -1 is not achievable
    }
    
    int f(int index, int target, vector<int>& coins, vector<vector<int>>& dp) {
        // Base case: from index-1 -> 0
        if (index == 0) {
            // target sum is divisible by the first element
            if (target % coins[0] == 0)
                return target / coins[0]; 
            else
                return 1e9; 
        }
        if (dp[index][target] != -1) return dp[index][target];

        int notpick = f(index - 1, target, coins, dp);
        int pick = 1e9;
        if (target >= coins[index]) {
            pick = 1 + f(index, target - coins[index], coins, dp); 
        }

        return dp[index][target] = min(pick, notpick);
    }
};
