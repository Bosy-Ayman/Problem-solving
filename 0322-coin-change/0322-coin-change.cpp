class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int index=coins.size();
        vector<int>prev(amount+1),curr(amount+1,0);

        // Base case: from 0->index-1
       
            prev[0]=0;
        
        for (int i=1; i<= amount;i++) {
            prev[i]=1e9; 
        }

        
        for (int ind =1;ind<= index;ind++) {
            for (int T = 0;T <= amount; T++) {
                int notpick = prev[T];
                int pick = 1e9;
                if (T >= coins[ind-1]) {
                    pick = 1 + curr[T-coins[ind-1]];
                }
                curr[T] = min(pick, notpick);
            }
             prev = curr;
        }

       
        if (prev[amount]==1e9) {
            return -1;
        } else {
            return prev[amount];
        }

    }
};
