// class Solution {
// public:
//     bool solve(int ind, int sum, vector<int>& nums, vector<vector<int>>dp){
//         if(sum == 0) return true;

//         if(ind == 0){
//             return nums[0] == sum;
//         }
//         if(dp[ind][sum] != -1) return dp[ind][sum];

//         int notTake = solve(ind-1, sum, nums, dp);
//         int take = 0;
//         if(nums[ind] <= sum) take = solve(ind-1,sum-nums[ind], nums, dp);

//         return dp[ind][sum] = take || notTake;
//     }
//     bool canPartition(vector<int>& nums) {
//         int sum = 0;
//         for(int i: nums){
//             sum += i;
//         }

//         if(sum % 2) return false;
//         sum = sum/2;
//         int n= nums.size();
//         vector<vector<int>>dp(n, vector<int>(sum+1, -1));
//         return solve(n-1, sum, nums, dp);
//     }
// };


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i: nums){
            sum += i;
        }

        if(sum % 2) return false;
        sum = sum/2;
        int n= nums.size();
        vector<vector<bool>>dp(n, vector<bool>(sum+1, false));
        
        for(int i=0; i< n; i++){
            dp[i][0] = true;
        }
        if(nums[0] <= sum) {
            dp[0][nums[0]] = true;
        }

        for(int i = 1; i < n; i++){
            for(int tar = 1; tar<= sum; tar++){

                int notTake = dp[i-1][tar];
                int take = 0;
                if(nums[i] <= tar) take = dp[i-1][tar-nums[i]];

                dp[i][tar] = take || notTake;
            }
        }
        //bool ans = take || notTake;
        return dp[n-1][sum];
    }
};