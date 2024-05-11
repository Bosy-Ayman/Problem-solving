class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max = 0;
        for(auto x:nums) max = std::max(max,x);
        int total = 0 ;
        for(int i = k; i > 0; i--) { 
            total += max;
            max++; 
        }
        return total;
    }
};
