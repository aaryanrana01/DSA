//Coin change 1

class Solution {
public:
    int solve(int ind, int amount, vector<int>& coins, vector<vector<int>>&dp){
        if(ind == 0){
            if(amount % coins[ind] == 0)return amount/ coins[ind];
            return 1e9;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notTake = solve(ind-1, amount, coins, dp);
        int take = 1e9;
        if(coins[ind] <= amount) take = 1+ solve(ind, amount-coins[ind], coins, dp);

        int ans = min(take, notTake);
        return dp[ind][amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans = solve(n-1, amount, coins, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};

