class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int result1 =robHelper(nums, 1,n-1);
        int result2 = robHelper(nums, 0,n-2);
        return max(result1, result2);
    }
    
private:
    int robHelper(vector<int>& nums,int start,int end) {
        int prevMax = 0, currMax = 0;
        for (int i = start; i <= end;i++) {
            int temp = currMax;
            currMax = max(prevMax + nums[i], currMax);
            prevMax = temp;
        }
        return currMax;
    }
    
    int robber(int index ,vector<int>& v){
        vector<int> temp1;
        vector<int>temp2;
        int size = v.size();
        if(size == 1)return v[0];
        int res1 = 0;
        int res2 = 0; 
        for(int i = 0 ;i<v.size();i++){
            if(i!=0) temp1.push_back(v[i]);
            if(i!=size-1) temp2.push_back(v[i]);
            res1 = rob(temp1); 
            res2 = rob(temp2); 
        }
        return max(res1,res2);
    }
};
