class Solution {
public:
    int rob(vector<int>& nums) {
        int index = nums.size();
        vector<int> dp(index + 1, -1); 
        return rob(nums, index, dp);
    }

private:
    int rob(vector<int>& nums, int index, vector<int>& dp) {
        if (index == 0) return 0; 
        if (index < 0) return 0; 

        if (dp[index] != -1) return dp[index]; // Check if value already computed

        int pick = nums[index - 1] + rob(nums, index - 2, dp); // Rob current house
        int nonpick = rob(nums, index - 1, dp); // Skip current house

        // Store the maximum amount that can be robbed up to the current house
        return dp[index] = max(pick, nonpick);
    }
};
