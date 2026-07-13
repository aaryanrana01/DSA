class Solution {
public:
    //int ans;
    int solve(vector<int>& nums){
        // if(ind == 0) return nums[0];
        // int extend = nums[ind] + solve(nums, ind-1);

        // int newStart = nums[ind];
        // int curr = max(extend, newStart);
        // ans = max(ans, curr);

        // return curr;

        int n = nums.size();
        vector<int>dp(n,0);
        dp[0] = nums[0];
        int ans = dp[0];

        for(int i = 1; i<n; i++){
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    int maxSubArray(vector<int>& nums) {
        //ans = nums[0];
        int n = nums.size();
        return solve(nums); 
    }
};